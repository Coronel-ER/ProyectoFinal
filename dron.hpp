#ifndef DRON_HPP
#define DRON_HPP

#include <SFML/Graphics.hpp>

class Dron {
private:
    sf::Sprite sprite;
    sf::Texture textura;
    sf::Vector2f velocidad;

public:
    Dron();
    void mover();
    void dibujar(sf::RenderWindow& ventana);
    const sf::Sprite& getSprite() const;
};

#endif
