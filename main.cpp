#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include "Simulador.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "CETYSWings - Menu");

    sf::Font TitleFont;
    if (!TitleFont.loadFromFile("recursos/PixelTitle.ttf")) {
        std::cerr << "Error al cargar la fuente del titulo\n";
        return -1;
    }

    sf::Font font;
    if (!font.loadFromFile("recursos/PixelFont.ttf")) {
        std::cerr << "Error al cargar la fuente\n";
        return -1;
    }

    Menu* menu = new Menu(window, font, TitleFont); // uso explícito new para el menu
    int seleccion = menu->mostrarMenu();
    delete menu; // liberación explícita

    if (seleccion >= 1 && seleccion <= 3) {
        Simulador simulador;
        simulador.setEscenario(seleccion);
        simulador.ejecutar();
    }

    return 0;
}
