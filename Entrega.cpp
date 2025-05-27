#include "Entrega.hpp"

Entrega::Entrega(sf::Vector2f pos, const std::string& nombre)
    : posicion(pos), entregada(false), nombreZona(nombre), puntos(5), figura(15.f) {
    figura.setFillColor(sf::Color::Red);
    figura.setPosition(posicion);
    figura.setOrigin(15.f, 15.f); // Origen en centro para mejor posición
}

Entrega::~Entrega() {}

void Entrega::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(figura);
}

void Entrega::entregar() {
    entregada = true;
    figura.setFillColor(sf::Color::Green);
    std::cout << "Entrega en zona \"" << nombreZona << "\" realizada." << std::endl;
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

std::string Entrega::getNombreZona() const {
    return nombreZona;
}

void Entrega::mostrarInfo() const {
    std::cout << "Zona: " << nombreZona << ", Pos: (" << posicion.x << ", " << posicion.y << ")"
              << ", Puntos: " << puntos << ", Estado: " << (entregada ? "Entregada" : "Pendiente") << std::endl;
}

// --------- Implementación EntregaEspecial ---------

EntregaEspecial::EntregaEspecial(sf::Vector2f pos, const std::string& nombre, int bono)
    : Entrega(pos, nombre), bono(bono) {
    puntos += bono; // Bono extra a puntaje base
    figura.setFillColor(sf::Color::Blue);
}

EntregaEspecial::~EntregaEspecial() {}

void EntregaEspecial::dibujar(sf::RenderWindow& ventana) {
    // Dibujar con distinto contorno para diferenciar
    figura.setOutlineThickness(3.f);
    figura.setOutlineColor(sf::Color::Yellow);
    ventana.draw(figura);
}

void EntregaEspecial::entregar() {
    entregada = true;
    figura.setFillColor(sf::Color::Cyan);
    std::cout << "Entrega especial en zona \"" << nombreZona << "\" realizada con bono " << bono << "." << std::endl;
}

int EntregaEspecial::getPuntos() const {
    return puntos;
}

int EntregaEspecial::getBono() const {
    return bono;
}

void EntregaEspecial::mostrarInfo() const {
    Entrega::mostrarInfo();
    std::cout << "  Bono extra: " << bono << std::endl;
}
