#include "Juego.hpp"
#include <iostream>

Juego::Juego() : ventana(sf::VideoMode(800, 600), "CETYSWings - Simulador de Entregas: Tijuana") {
    ventana.setFramerateLimit(60);
    nivelActual = 1;
    entregas.push_back(new Entrega(sf::Vector2f(300, 100), "Zona Río"));
    entregas.push_back(new EntregaEspecial(sf::Vector2f(600, 200), "Otay", 10));
    entregas.push_back(new Entrega(sf::Vector2f(100, 100), "Playas de Tijuana"));
    entregas.push_back(new Entrega(sf::Vector2f(200, 150), "La Mesa"));
    entregas.push_back(new EntregaEspecial(sf::Vector2f(250, 250), "5 y 10", 10));
    entregas.push_back(new Entrega(sf::Vector2f(400, 100), "Zona Centro"));
    entregas.push_back(new EntregaEspecial(sf::Vector2f(500, 300), "El Florido", 10));
    entregas.push_back(new Entrega(sf::Vector2f(600, 400), "La Presa"));
    entregas.push_back(new EntregaEspecial(sf::Vector2f(150, 500), "Bosse", 10));
    entregas.push_back(new Entrega(sf::Vector2f(700, 100), "CETYS Universidad"));
    entregas.push_back(new EntregaEspecial(sf::Vector2f(350, 450), "Sticky", 10));
    entregas.push_back(new Entrega(sf::Vector2f(50, 200), "COBACH"));
    entregas.push_back(new EntregaEspecial(sf::Vector2f(650, 500), "PFLC", 10));
    entregas.push_back(new Entrega(sf::Vector2f(200, 50), "CECUT"));
    entregas.push_back(new EntregaEspecial(sf::Vector2f(100, 300), "Club Campestre", 10));
    entregas.push_back(new Entrega(sf::Vector2f(450, 200), "Plaza Península"));
    entregas.push_back(new EntregaEspecial(sf::Vector2f(300, 300), "Chapultepec", 10));
}

void Juego::ejecutar() {
    while (ventana.isOpen()) {
        procesarEventos();
        actualizar();
        renderizar();
    }
}

void Juego::procesarEventos() {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed)
            ventana.close();
    }
    dron.mover();
}

void Juego::actualizar() { 
    for (auto& e : entregas) {
        if (!e->estaEntregada() && Colisiones::detectar(dron.getSprite(), e->posicion)) {
            e->entregar();
        }
    }

    bool todoEntregado = true;
    for (auto& e : entregas) {
        if (!e->estaEntregada()) {
            todoEntregado = false;
            break;
        }
    }
    if (todoEntregado && nivelActual < 3) { //Funcion de desbloqueo niveles, limite de 3 niveles
        nivelActual++;
        std::cout << "¡Nivel " << nivelActual << " desbloqueado!
";
    }
}

void Juego::renderizar() { //Renderizacion de ventana de simulador
    ventana.clear(sf::Color::Cyan);
    for (auto& e : entregas)
        e->dibujar(ventana);
    dron.dibujar(ventana);
    ventana.display();
}
