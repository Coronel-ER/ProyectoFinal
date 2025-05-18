//usare arial,tff para la fuente por que la viene predetermianda no me gusta y se ve fea
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Juego.hpp"

void iniciarNivel(int nivel) {
    std::cout << "Iniciando Nivel " << nivel << "...
";
    Juego juego;
    juego.setNivel(nivel);
    juego.ejecutar();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu de Entregas");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "No se pudo cargar la fuente.
";
        return -1;
    }
