#ifndef SIMULADOR_HPP
#define SIMULADOR_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Dron.hpp"
#include "Entrega.hpp"
#include "EntregaEspecial.hpp"

//clase simu
class Simulador {
private:
    sf::RenderWindow ventana;  // la ventana donde se va a mostrar el simulador
    Dron dron;                 // muetsa el dron
    std::vector<Entrega*> entregas; // las entregas que hay que hacer (normales y especiales)
    int nivelActual;          // para saber en qué nivel andamos

public:
    simulador();                  // constructor (inicializa todo)
    void setNivel(int nivel); // para cambiar de nivel desde el menú
    void ejecutar();          // corre el simulador (loop principal)
    void procesarEventos();   // revisa lo que hace el usuario (teclas, cerrar ventana, etc.)
    void actualizar();        // aquí se actualiza la lógica del simulador
    void renderizar();        // se encarga de pintar todo en pantalla
};

#endif
