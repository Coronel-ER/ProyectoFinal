#include "Juego.hpp"
#include <iostream>

Juego::Juego() : ventana(sf::VideoMode(800, 600), "CETYSWings - Simulador de Entregas: Tijuana"), nivelActual(0) {
    ventana.setFramerateLimit(60);
    cargarNiveles();
}

void Juego::cargarNiveles() {
    Nivel nivel1;
    nivel1.agregarEntrega(new Entrega(sf::Vector2f(300, 100), "Zona Río"));
    nivel1.agregarEntrega(new EntregaEspecial(sf::Vector2f(600, 200), "Otay", 10));
    nivel1.agregarEntrega(new Entrega(sf::Vector2f(100, 100), "Playas de Tijuana"));

    Nivel nivel2;
    nivel2.agregarEntrega(new Entrega(sf::Vector2f(200, 150), "La Mesa"));
    nivel2.agregarEntrega(new EntregaEspecial(sf::Vector2f(250, 250), "5 y 10", 10));
    nivel2.agregarEntrega(new Entrega(sf::Vector2f(400, 100), "Zona Centro"));

    Nivel nivel3;
    nivel3.agregarEntrega(new EntregaEspecial(sf::Vector2f(500, 300), "El Florido", 10));
    nivel3.agregarEntrega(new Entrega(sf::Vector2f(600, 400), "La Presa"));
    nivel3.agregarEntrega(new Entrega(sf::Vector2f(700, 100), "CETYS Universidad"));

    niveles.push_back(nivel1);
    niveles.push_back(nivel2);
    niveles.push_back(nivel3);
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
    Nivel& nivel = niveles[nivelActual];
    nivel.actualizarEntregas(dron);

    if (nivel.entregasCompletas() && nivelActual < niveles.size() - 1) {
        nivelActual++;
        std::cout << "¡Nivel " << (nivelActual + 1) << " desbloqueado!\n";
    }
}

void Juego::renderizar() {
    ventana.clear(sf::Color::Cyan);
    niveles[nivelActual].dibujarEntregas(ventana);
    dron.dibujar(ventana);
    ventana.display();
}
