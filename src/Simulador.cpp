#include "Simulador.hpp"
#include "Colisiones.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>  // Para formateo de texto

Simulador::Simulador()
    : ventana(sf::VideoMode(800, 600), "CETYSWings - Nivel"),
      escenarioActual(1), puntuacion(0), mensajeVisible(false), tiempoMaximo(90.0f) {

    ventana.setFramerateLimit(60);

    if (!fuente.loadFromFile("recursos/arial.ttf")) {
        std::cerr << "Error: No se pudo cargar la fuente.\n";
    }

    textoMensaje.setFont(fuente);
    textoMensaje.setCharacterSize(24);
    textoMensaje.setFillColor(sf::Color::Yellow);
    textoMensaje.setPosition(200, 550);
}

void Simulador::setEscenario(int nivel) {
    escenarioActual = nivel;
    puntuacion = 0;
    entregas.clear();
    mensajeVisible = false;
    relojEscenario.restart();

    // Carga entregas con diferentes puntos y posiciones
    if (nivel == 1) {
        entregas.push_back(std::make_unique<Entrega>(sf::Vector2f(300, 100), "Zona Río"));
        entregas.push_back(std::make_unique<Entrega>(sf::Vector2f(500, 200), "Playas"));
        entregas.push_back(std::make_unique<Entrega>(sf::Vector2f(400, 300), "Zona Centro"));
        entregas.push_back(std::make_unique<Entrega>(sf::Vector2f(200, 400), "La Presa"));
    } else if (nivel == 2) {
        entregas.push_back(std::make_unique<EntregaEspecial>(sf::Vector2f(600, 300), "Otay", 10));
        entregas.push_back(std::make_unique<Entrega>(sf::Vector2f(400, 250), "La Mesa"));
        entregas.push_back(std::make_unique<EntregaEspecial>(sf::Vector2f(150, 350), "El Florido", 15));
        entregas.push_back(std::make_unique<Entrega>(sf::Vector2f(300, 450), "5 y 10"));
    } else if (nivel == 3) {
        entregas.push_back(std::make_unique<EntregaEspecial>(sf::Vector2f(150, 500), "CETYS Universidad", 20));
        entregas.push_back(std::make_unique<Entrega>(sf::Vector2f(100, 100), "Zona Centro"));
        entregas.push_back(std::make_unique<EntregaEspecial>(sf::Vector2f(600, 150), "Chapultepec", 25));
        entregas.push_back(std::make_unique<Entrega>(sf::Vector2f(250, 350), "Club Campestre"));
    }

    // Carga dinámica del mapa de fondo según escenario
    std::string rutaMapa = "recursos/mapa" + std::to_string(nivel) + ".png";
    if (!fondoMapaTex.loadFromFile(rutaMapa)) {
        std::cerr << "Error: No se pudo cargar el mapa del escenario " << nivel << ".\n";
    }
    fondoMapa.setTexture(fondoMapaTex);
}

void Simulador::ejecutar() {
    while (ventana.isOpen()) {
        procesarEventos();
        actualizar();
        renderizar();

        // Termina si se cumple tiempo o se completan entregas
        if (relojEscenario.getElapsedTime().asSeconds() >= tiempoMaximo || todasEntregasCompletadas()) {
            guardarPuntaje();
            mostrarFinDeEscenario();
            break;
        }
    }
}

void Simulador::procesarEventos() {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            ventana.close();
    }
    dron.mover();
}

void Simulador::actualizar() {
    for (auto& e : entregas) {
        if (!e->estaEntregada() && Colisiones::detectar(dron.getSprite(), e->getPosicion())) {
            e->entregar();
            puntuacion += e->getPuntos();

            // Mensaje de retroalimentación para la entrega completada
            mensajeTexto = "¡Entrega completada: +" + std::to_string(e->getPuntos()) + " pts!";
            mensajeVisible = true;
            mensajeTimer.restart();
        }
    }

    // Ocultar mensaje después de 2.5 segundos
    if (mensajeVisible && mensajeTimer.getElapsedTime().asSeconds() > 2.5f) {
        mensajeVisible = false;
    }
}

void Simulador::renderizar() {
    ventana.clear();
    ventana.draw(fondoMapa);

    for (auto& e : entregas)
        e->dibujar(ventana);

    dron.dibujar(ventana);

    // Mostrar puntaje
    sf::Text textoPuntaje("Puntos: " + std::to_string(puntuacion), fuente, 20);
    textoPuntaje.setPosition(10.f, 10.f);
    textoPuntaje.setFillColor(sf::Color::White);
    ventana.draw(textoPuntaje);

    // Barra de progreso para el tiempo
    float tiempoRestante = tiempoMaximo - relojEscenario.getElapsedTime().asSeconds();
    sf::RectangleShape barraTiempo(sf::Vector2f(200, 20));
    barraTiempo.setFillColor(sf::Color::Green);
    barraTiempo.setSize(sf::Vector2f(200 * (tiempoRestante / tiempoMaximo), 20));
    barraTiempo.setPosition(600.f, 10.f);
    ventana.draw(barraTiempo);

    // Mostrar tiempo restante como texto
    sf::Text textoTiempo("Tiempo: " + std::to_string(static_cast<int>(tiempoRestante)) + "s", fuente, 20);
    textoTiempo.setPosition(650.f, 10.f);
    textoTiempo.setFillColor(sf::Color::Cyan);
    ventana.draw(textoTiempo);

    // Mostrar mensaje temporal de entrega completada
    if (mensajeVisible) {
        textoMensaje.setString(mensajeTexto);
        textoMensaje.setFillColor(sf::Color::Yellow); // Resalta el mensaje
        ventana.draw(textoMensaje);
    }

    ventana.display();
}

bool Simulador::todasEntregasCompletadas() const {
    for (const auto& e : entregas) {
        if (!e->estaEntregada())
            return false;
    }
    return true;
}

void Simulador::guardarPuntaje() const {
    std::ofstream archivo("puntaje.txt", std::ios::app);
    archivo << "Escenario " << escenarioActual << ": " << puntuacion << " puntos\n";
    archivo.close();
}

void Simulador::mostrarFinDeEscenario() {
    ventana.clear(sf::Color::Black);
    sf::Text fin("ESCENARIO COMPLETADO", fuente, 40);
    fin.setFillColor(sf::Color::Green);
    fin.setPosition(180, 250);
    ventana.draw(fin);

    sf::Text puntos("Puntaje final: " + std::to_string(puntuacion), fuente, 24);
    puntos.setPosition(260, 320);
    puntos.setFillColor(sf::Color::White);
    ventana.draw(puntos);

    ventana.display();
    sf::sleep(sf::seconds(4));
}

// Nuevos métodos públicos para controlar tiempo y obtener puntaje

void Simulador::setTiempoMaximo(float segundos) {
    tiempoMaximo = segundos;
}

int Simulador::getPuntuacion() const {
    return puntuacion;
}
