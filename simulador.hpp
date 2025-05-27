#ifndef SIMULADOR_HPP
#define SIMULADOR_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>

#include "Dron.hpp"
#include "Entrega.hpp"

/*
 * Clase Simulador
 * - Controla el flujo completo del juego: lógica, tiempos, puntajes, niveles.
 * - Usa punteros inteligentes para manejo seguro de memoria.
 * - Gestiona la ventana, eventos y renderizado con SFML.
 * - Permite configuración de diferentes escenarios y carga dinámica de recursos.
 */
class Simulador {
private:
    sf::RenderWindow ventana;
    int escenarioActual;
    int puntuacion;
    sf::Font fuente;
    sf::Text textoMensaje;
    bool mensajeVisible;
    std::string mensajeTexto;
    sf::Clock mensajeTimer;
    sf::Clock relojEscenario;
    float tiempoMaximo;

    sf::Texture fondoMapaTex;
    sf::Sprite fondoMapa;

    Dron dron;
    std::vector<std::unique_ptr<Entrega>> entregas;

    // Métodos auxiliares privados
    void procesarEventos();
    void actualizar();
    void renderizar();

    bool todasEntregasCompletadas() const;
    void guardarPuntaje() const;
    void mostrarFinDeEscenario();

public:
    Simulador();

    void setEscenario(int nivel);
    void ejecutar();

    // Métodos públicos para manipular tiempo y puntajes (ampliable)
    void setTiempoMaximo(float segundos);
    int getPuntuacion() const;
};

#endif
