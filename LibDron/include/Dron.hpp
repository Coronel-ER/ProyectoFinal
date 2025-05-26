#ifndef DRON_HPP
#define DRON_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Dron {
private:
    sf::Sprite sprite;
    sf::Texture textura;
    sf::Vector2f posicion;
    float velocidad;

public:
    Dron();
    virtual ~Dron();

    void mover();
    void mover(float dx, float dy);

    void dibujar(sf::RenderWindow& ventana);

    sf::Sprite& getSprite();

    sf::Vector2f getPosicion() const;
};

#endif // DRON_HPP
