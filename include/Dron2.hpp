#ifndef DRON_HPP
#define DRON_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

/*
 * Clase Dron
 * - Representa al dron con su sprite, posición, velocidad y control de textura.
 * - Permite mover el dron tanto con teclado como por desplazamiento personalizado (sobrecarga).
 * - Implementa métodos para obtener posición, sprite y control de la textura.
 * - Encapsulamiento completo de atributos.
 */
class Dron {
private:
    sf::Sprite sprite;
    sf::Texture textura;
    sf::Vector2f posicion;
    float velocidad;

public:
    Dron();
    virtual ~Dron();

    // Mueve el dron con controles predeterminados de teclado
    void mover();

    // Sobrecarga de mover para mover el dron con desplazamiento arbitrario (dx, dy)
    void mover(float dx, float dy);

    // Dibuja el sprite del dron en la ventana
    void dibujar(sf::RenderWindow& ventana);

    // Devuelve el sprite para manipulación externa
    sf::Sprite& getSprite();

    // Obtiene la posición del dron
    sf::Vector2f getPosicion() const;

    // Carga una nueva textura para el dron, permitiendo cambios de aspecto dinámicos
    void cambiarTextura(const std::string& archivo);
};

#endif 
