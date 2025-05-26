#include "Dron.hpp"
#include <SFML/Window/Keyboard.hpp>

Dron::Dron() : posicion(100.f, 100.f), velocidad(3.5f) {
    if (!textura.loadFromFile("recursos/download.jpeg")) {
        std::cerr << "Error: No se pudo cargar la textura del dron (download.jpeg).\\n";
    }
    sprite.setTexture(textura);
    sprite.setPosition(posicion);
}

Dron::~Dron() {}

void Dron::mover() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        posicion.x -= velocidad;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        posicion.x += velocidad;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        posicion.y -= velocidad;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        posicion.y += velocidad;
    }
    sprite.setPosition(posicion);
}

void Dron::mover(float dx, float dy) {
    posicion.x += dx * velocidad;
    posicion.y += dy * velocidad;
    sprite.setPosition(posicion);
}

void Dron::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(sprite);
}

sf::Sprite& Dron::getSprite() {
    return sprite;
}

sf::Vector2f Dron::getPosicion() const {
    return posicion;
}

