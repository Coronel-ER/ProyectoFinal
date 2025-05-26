#include "Entrega.hpp"
#include <iostream>

Entrega::Entrega(sf::Vector2f pos, const std::string& nombre)
    : posicion(pos), entregada(false), nombreZona(nombre), puntos(5), figura(15.f) {
    figura.setFillColor(sf::Color::Red);
    figura.setPosition(posicion);
}

Entrega::~Entrega() {}

void Entrega::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(figura);
}

void Entrega::entregar() {
    entregada = true;
    figura.setFillColor(sf::Color::Green);
}

bool Entrega::estaEntregada() const {
    return entregada;
}

sf::Vector2f Entrega::getPosicion() const {
    return posicion;
}

int Entrega::getPuntos() const {
    return puntos;
}

EntregaEspecial::EntregaEspecial(sf::Vector2f pos, const std::string& nombre, int bono)
    : Entrega(pos, nombre), bono(bono) {
    puntos += bono;
    figura.setFillColor(sf::Color::Blue);
}

EntregaEspecial::~EntregaEspecial() {}

void EntregaEspecial::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(figura);
}

void EntregaEspecial::entregar() {
    entregada = true;
    figura.setFillColor(sf::Color::Cyan);
}

int EntregaEspecial::getPuntos() const {
    return puntos;
}

