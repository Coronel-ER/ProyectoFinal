#include "Entrega.hpp"
#include <iostream>

Entrega::Entrega(const sf::Vector2f& pos, const std::string& destino)
    : posicion(pos), entregada(false), destino(destino) {}

void Entrega::entregar() {
    entregada = true;
    std::cout << "Entrega realizada en " << destino << ".\n";
}

void Entrega::dibujar(sf::RenderWindow& ventana) const {
