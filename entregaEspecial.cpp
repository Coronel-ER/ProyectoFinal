#include "EntregaEspecial.hpp"
#include <iostream>

EntregaEspecial::EntregaEspecial(const sf::Vector2f& pos, const std::string& destino, int bono)
    : Entrega(pos, destino), bonoTiempo(bono) {}

void EntregaEspecial::entregar() {
    entregada = true;
    std::cout << "Entrega especial realizada en " << destino << "! Bono: +" << bonoTiempo << " segundos.\n";
}
