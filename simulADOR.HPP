#ifndef JUEGO_HPP
#define JUEGO_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Dron.hpp"
#include "Entrega.hpp"
#include "EntregaEspecial.hpp"

class Juego {
private:
    sf::RenderWindow ventana;
    Dron dron;
    std::vector<Entrega*> entregas;
    int nivelActual;

public:
    Juego();
    void setNivel(int nivel);
    void ejecutar();
    void procesarEventos();
    void actualizar();
    void renderizar();
};

#endif
