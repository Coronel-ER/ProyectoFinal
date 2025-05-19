#ifndef SIMULADOR_HPP
#define SIMULADOR_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Entrega.hpp"
#include "EntregaEspecial.hpp"
#include "Dron.hpp"

class Simulador {
private:
    sf::RenderWindow ventana;
    std::vector<Entrega*> entregas;
    Dron dron;
    int nivelActual;

    void procesarEventos();
    void actualizar();
    void renderizar();

public:
    Simulador();
    void setNivel(int nivel);
    void ejecutar();
};

#endif
