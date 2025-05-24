#ifndef SIMULADOR_HPP
#define SIMULADOR_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Dron.hpp"
#include "Entrega.hpp"
#include "EntregaEspecial.hpp"

class Simulador {
private:
    sf::RenderWindow ventana;                     // Ventana de simulación
    Dron dron;                                    // El dron del jugador
    std::vector<std::unique_ptr<Entrega>> entregas; // Lista de entregas
    int escenarioActual;                          // Escenario actual (1, 2 o 3)
    int puntuacion;                               // Puntos acumulados

    sf::Font fuente;                              // Fuente para mostrar texto
    sf::Texture fondoMapaTex;                     // Textura del fondo de mapa
    sf::Sprite fondoMapa;                         // Sprite del fondo

    // Métodos internos del juego
    void procesarEventos();   // Maneja teclado, cerrar ventana
    void actualizar();        // Detecta entregas realizadas
    void renderizar();        // Dibuja todo
    void cargarEscenario(int nivel); // Carga entregas y elementos del escenario

public:
    Simulador();              // Constructor
    void setEscenario(int nivel); // Cambia el escenario activo
    void ejecutar();          // Loop principal del juego
};

#endif

