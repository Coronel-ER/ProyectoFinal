#ifndef ENTREGA_HPP
#define ENTREGA_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Entrega {
protected:
    sf::Vector2f posicion;
    std::string destino;
    bool entregada;
    sf::CircleShape forma;

public:
    Entrega(const sf::Vector2f& pos, const std::string& dest);
    virtual ~Entrega() {}
    virtual void entregar();
    virtual void dibujar(sf::RenderWindow& ventana);
    bool estaEntregada() const;
    sf::Vector2f getPosicion() const;
};

#endif
