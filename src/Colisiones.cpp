#include "Colisiones.hpp"

namespace Colisiones {
    bool detectar(const sf::Sprite& sprite1, const sf::Vector2f& punto) {
        return sprite1.getGlobalBounds().contains(punto);
    }
}
