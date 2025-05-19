#include "Entrega.hpp"
#include <iostream>

Entrega::Entrega(const sf::Vector2f& pos, const std::string& dest)
    : posicion(pos), destino(dest), entregada(false) {
    forma.setRadius(10.f);
    forma.setFillColor(sf::Color::Red);
    forma.setPosition(posicion);
}

void Entrega::entregar() {
    entregada = true;
    forma.setFillColor(sf::Color::Green);
    std::cout << "Entrega realizada en " << destino << "!
";
}

void Entrega::dibujar(sf::RenderWindow& ventana) {
    if (!entregada)
        ventana.draw(forma);
}

bool Entrega::estaEntregada() const {
    return entregada;
}

sf::Vector2f Entrega::getPosicion() const {
    return posicion;
}
