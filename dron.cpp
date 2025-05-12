#include "Dron.hpp"
#include <iostream> 

Dron::Dron() {
    if (!textura.loadFromFile("recursos/dron.png")) {
        std::cout << "Error: No se pudo cargar la imagen del dron.\n";
    }

    sprite.setTexture(textura);
    sprite.setScale(1.0f, 1.0f);
    sprite.setPosition(100.0f, 100.0f);
}

void Dron::mover() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) sprite.move(0, -3);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) sprite.move(0,  3);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) sprite.move(-3, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) sprite.move( 3, 0);
}

void Dron::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(sprite);
}

const sf::Sprite& Dron::getSprite() const {
    return sprite;
}
