#ifndef SIMULADOR_HPP
#define SIMULADOR_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>
#include "Dron.hpp"
#include "Entrega.hpp"
#include "EntregaEspecial.hpp"

class Simulador {
private:
    sf::RenderWindow ventana;                     // Ventana del juego
    Dron dron;                                    // Dron del jugador
    std::vector<std::unique_ptr<Entrega>> entregas; // Entregas activas
    int escenarioActual;                          // Número del escenario (nivel)
    int puntuacion;                               // Puntos acumulados

    sf::Font fuente;                              // Fuente para textos
    sf::Texture fondoMapaTex;                     // Textura del mapa
    sf::Sprite fondoMapa;                         // Sprite para el fondo del mapa

    // Sistema de mensajes temporales
    std::string mensajeTexto;
    bool mensajeVisible;
    sf::Text textoMensaje;
    sf::Clock mensajeTimer;

    // Temporizador del escenario
    sf::Clock relojEscenario;
    float tiempoMaximo; // en segundos

    // Métodos internos
    void procesarEventos();
    void actualizar();
    void renderizar();
    bool todasEntregasCompletadas();
    void guardarPuntaje();
    void mostrarFinDeEscenario();

public:
    Simulador();                      // Constructor
    void setEscenario(int nivel);    // Carga el escenario correspondiente
    void ejecutar();                 // Loop principal del simulador
};

#endif

#endif

