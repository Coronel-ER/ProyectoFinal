#ifndef DRON_HPP
#define DRON_HPP

#include <SFML/Graphics.hpp>

// esta clase es el dron, lo mueve, lo dibuja y listo
class Dron {
private:
    sf::Sprite sprite;      // el dibujo 64x64 del dron que se muestra en pantalla
    sf::Texture textura;    // la imagen que se le pone al sprite
    sf::Vector2f velocidad; // velocidad (por si más adelante quieres que se mueva más fluido)

public:
    Dron();  // constructor, carga la imagen y pone al dron en su posición inicial
    void mover(); // mueve al dron con las teclas 
    void dibujar(sf::RenderWindow& ventana); // dibuja el dron en la ventana que se le pase
    const sf::Sprite& getSprite() const; // para acceder al sprite (por ejemplo, para colisiones (que no esta listo todavia))  
};

#endif
