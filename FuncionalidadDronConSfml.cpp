#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dron sobre campo verde");
    window.setFramerateLimit(60);
// Estoy cargando la textura del dron desde un archivo (no salio)
    sf::Texture droneTexture;
    if (!droneTexture.loadFromFile("dron.png")) {
        return -1;// Si no se puede cargar, sale con error
    }

    sf::Sprite droneSprite;
    droneSprite.setTexture(droneTexture);
    droneSprite.setScale(0.3f, 0.3f);// esta creo que la voy a hacer un poco mas grande dependieno los avances de mis compañeros
    droneSprite.setPosition(400, 300);

    const float speed = 5.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) droneSprite.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) droneSprite.move(0, speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) droneSprite.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) droneSprite.move(speed, 0);
        //pintar el fonde de verde 
        window.clear(sf::Color(102, 204, 102));
        window.draw(droneSprite);
        window.display();
    }

    return 0;
}

