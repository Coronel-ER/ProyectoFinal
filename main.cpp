#include <SFML/Graphics.hpp>
#include "Simulador.hpp"
#include <iostream>
// Pendiente Crear Clase Menu

// Impresion del menu
int mostrarMenu(sf::RenderWindow& window, sf::Font& font) {
    // Arreglo de opciones
    std::vector<std::string> opciones = {
        "Iniciar Nivel 1",
        "Iniciar Nivel 2",
        "Iniciar Nivel 3",
        "Salir"
    };

    std::vector<sf::Text> textos;
    int seleccion = 0;

    // Impresion de las opciones
    for (size_t i = 0; i < opciones.size(); ++i) {
        sf::Text texto(opciones[i], font, 30);
        texto.setPosition(250, 200 + (i * 50));
        textos.push_back(texto);
    }

    // Bucle principal
    while (window.isOpen()) {
        sf::Event event;

        // Cerrar ventana
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Manejo de opciones
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) // Opcion anterior
                    seleccion = (seleccion + opciones.size() - 1) % opciones.size();
                if (event.key.code == sf::Keyboard::Down) // Siguiente opcion
                    seleccion = (seleccion + 1) % opciones.size();
                if (event.key.code == sf::Keyboard::Enter) // Elegir opcion
                    return seleccion + 1;
            }
        }

        // Display
        window.clear(sf::Color(100, 149, 237)); /// Fondo azul

        //Impresion del texto
        for (size_t i = 0; i < textos.size(); ++i) {
            // Efecto Hover
            if (i == seleccion)
                textos[i].setFillColor(sf::Color::Yellow); // Color de la opcion seleccionada
            else
                textos[i].setFillColor(sf::Color::White); // Color de las opciones no seleccionadas
            window.draw(textos[i]);
        }
        window.display();
    }

    return 4;
}

int main() {
    // Creacion de la ventana principal
    sf::RenderWindow window(sf::VideoMode(800, 600), "CETYSWings - Menu");

    // Cambio de fuente tipografica
    sf::Font font;
    if (!font.loadFromFile("recursos/arial.ttf")) {
        std::cerr << "Error al cargar la fuente
";
        return -1;
    }

    // Impresion del menu regresa la opcion seleccionada
    int seleccion = mostrarMenu(window, font);
    if (seleccion >= 1 && seleccion <= 3) {
        // Inicio del simulador
        Simulador simulador;
        simulador.setNivel(seleccion);
        simulador.ejecutar();
    }

    return 0;
}
