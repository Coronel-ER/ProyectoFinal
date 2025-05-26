#ifndef SIMULADOR_HPP
#define SIMULADOR_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>

#include "Dron.hpp"
#include "Entrega.hpp"

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

public:
    Simulador();

    void setEscenario(int nivel);
    void ejecutar();

private:
    void procesarEventos();
    void actualizar();
    void renderizar();

    bool todasEntregasCompletadas();
    void guardarPuntaje();
    void mostrarFinDeEscenario();
};

#endif

