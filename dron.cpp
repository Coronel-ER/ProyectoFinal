#include "Dron.hpp"
#include <iostream> 

// constructor del dron, aquí cargamos la imagen y lo dejamos listo para despegar
Dron::Dron() {
    if (!textura.loadFromFile("recursos/dron.png")) {
        std::cout << "Error: No se pudo cargar la imagen del dron.\n"; // por si falla la carga
    }

    sprite.setTexture(textura);           // le ponemos la imagen al sprite
    sprite.setScale(1.0f, 1.0f);          // sin zoom ni nada raro
    sprite.setPosition(100.0f, 100.0f);   // lo soltamos por aquí, que se vea
}

// esta función mueve el dron según las teclas W, A, S, D
void Dron::mover() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) sprite.move(0, -3); // arriba
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) sprite.move(0,  3); // abajo
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) sprite.move(-3, 0); // izquierda
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) sprite.move( 3, 0); // derecha
}

// función para dibujar el dron en la ventana, sin esto no se ve nada
void Dron::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(sprite); // lo pintamos en pantalla
}

// función para acceder al sprite (se ocuparia para coliciones)
const sf::Sprite& Dron::getSprite() const {
    return sprite;
}
