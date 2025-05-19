#include "Simulador.hpp"
#include "Colisiones.hpp"
#include <iostream>

Simulador::Simulador() : ventana(sf::VideoMode(800, 600), "CETYSWings - Nivel"), nivelActual(1) {
    ventana.setFramerateLimit(60);
}

void Simulador::setNivel(int nivel) {
    nivelActual = nivel;
    entregas.clear();

    if (nivel == 1) {
        entregas.push_back(new Entrega(sf::Vector2f(300, 100), "Zona Río"));
        entregas.push_back(new Entrega(sf::Vector2f(500, 200), "Playas"));
        entregas.push_back(new Entrega(sf::Vector2f(400, 300), "Zona Centro"));
        entregas.push_back(new Entrega(sf::Vector2f(200, 400), "La Presa"));
    } else if (nivel == 2) {
        entregas.push_back(new EntregaEspecial(sf::Vector2f(600, 300), "Otay", 10));
        entregas.push_back(new Entrega(sf::Vector2f(400, 250), "La Mesa"));
        entregas.push_back(new EntregaEspecial(sf::Vector2f(150, 350), "El Florido", 15));
        entregas.push_back(new Entrega(sf::Vector2f(300, 450), "5 y 10"));
    } else if (nivel == 3) {
        entregas.push_back(new EntregaEspecial(sf::Vector2f(150, 500), "CETYS Universidad", 20));
        entregas.push_back(new Entrega(sf::Vector2f(100, 100), "Zona Centro"));
        entregas.push_back(new EntregaEspecial(sf::Vector2f(600, 150), "Chapultepec", 25));
        entregas.push_back(new Entrega(sf::Vector2f(250, 350), "Club Campestre"));
    }
}

void Simulador::ejecutar() {
    while (ventana.isOpen()) {
        procesarEventos();
        actualizar();
        renderizar();
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
        }
    }
}

void Simulador::renderizar() {
    ventana.clear(sf::Color(102, 204, 102));
    for (auto& e : entregas)
        e->dibujar(ventana);
    dron.dibujar(ventana);
    ventana.display();
}
