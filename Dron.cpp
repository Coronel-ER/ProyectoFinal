#include "Dron.hpp"
#include <iostream>

Dron::Dron() {
    if (!textura.loadFromFile("recursos/dron.png")) {
        std::cerr << "Error: No se pudo cargar la imagen del dron.
";
    }
    sprite.setTexture(textura);
    sprite.setScale(0.6f, 0.6f);
    sprite.setPosition(100.f, 100.f);
}

void Dron::mover() {
    const float speed = 3.5f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) sprite.move(0, -speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) sprite.move(0,  speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) sprite.move(-speed, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) sprite.move( speed, 0);
}

void Dron::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(sprite);
}

const sf::Sprite& Dron::getSprite() const {
    return sprite;
}
