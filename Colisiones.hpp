#ifndef COLISIONES_HPP
#define COLISIONES_HPP

#include <SFML/Graphics.hpp>

class Colisiones {
public:
    static bool detectar(const sf::Sprite& a, const sf::Vector2f& punto) {
        return a.getGlobalBounds().contains(punto);
    }
};

#endif
