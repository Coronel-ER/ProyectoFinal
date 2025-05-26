#ifndef COLISIONES_HPP
#define COLISIONES_HPP

#include <SFML/Graphics.hpp>

namespace Colisiones {
    bool detectar(const sf::Sprite& sprite1, const sf::Vector2f& punto);
}

#endif
