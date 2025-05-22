#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Simulador.hpp"


class Menu {
private:
    sf::RenderWindow& window;
    sf::Font& font;
    sf::Font& TitleFont;
    std::vector<std::string> opciones;
    std::vector<sf::Text> textos;
    int seleccion;

public:
    // ---------- Constructor ----------
    Menu(sf::RenderWindow& window, sf::Font& font, sf::Font& TitleFont) : window(window), font(font), TitleFont(TitleFont), seleccion(0) {
        opciones = {
            "Iniciar Escenario 1",
            "Iniciar Escenario 2",
            "Iniciar Escenario 3",
            "Salir"
        };
    }

    // ---------- Funciones ----------

    // Impresion del menu
    int mostrarMenu() {
        // Impresion Titulo
        sf::Text titulo(TitleFont);
        titulo.setString("CETYSwings");
        titulo.setCharacterSize(65);
        titulo.setFillColor(sf::Color(20, 225, 20));
        titulo.setPosition({ ((800.f - titulo.getLocalBounds().size.x) / 2), 80 });

        // Impresion de las opciones
        for (size_t i = 0; i < opciones.size(); ++i) {
            sf::Text texto(font);
            texto.setString(opciones[i]);
            texto.setCharacterSize(30);
            texto.setPosition({ ((800.f - texto.getLocalBounds().size.x) / 2), 250.f + i * 50 });
            textos.push_back(texto);
        }

        // Bucle principal
        while (window.isOpen()) {
            // Crear ventana
            while (const std::optional event = window.pollEvent()) {
                // Cerrar ventana
                if (event->is <sf::Event::Closed>()) {
                    window.close();
                }

                // Manejo de opciones
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
                    seleccion = (seleccion + opciones.size() - 1) % opciones.size();
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
                    seleccion = (seleccion + 1) % opciones.size();
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
                    return seleccion + 1;
                }
            }

            // ---------- Display ----------

            // Fondo
            sf::Texture texture("recursos/MenuBG.png");
            sf::Sprite sprite(texture);

            window.clear(sf::Color(0, 0, 0));
            window.draw(sprite);

            // Impresion del titulo
            window.draw(titulo);

            //Impresion del texto
            for (size_t i = 0; i < textos.size(); ++i) {
                // Efecto Hover
                if (i == seleccion)
                    textos[i].setFillColor(sf::Color::Green);
                else
                    textos[i].setFillColor(sf::Color::Black);
                window.draw(textos[i]);
            }


            window.display();
        }
        return 4;
    }

};


int main() {
    // Creacion de la ventana principal
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }, 24), "CETYSWings - Menu");

    // Inicializacion de la fuente del titulo
    sf::Font TitleFont;
    if (!TitleFont.openFromFile("recursos/PixelTitle.ttf")) { // Cambio de fuente tipografica
        std::cerr << "Error al cargar la fuente del titulo";
        return -1;
    }

    // Inicializacion de la fuente 
    sf::Font font;
    if (!font.openFromFile("recursos/PixelFont.ttf")) { // Cambio de fuente tipografica
        std::cerr << "Error al cargar la fuente";
        return -1;
    }

    // Creacion del menu
    Menu menu(window, font, TitleFont);

    // Impresion del menu y captura de su resultado
    int seleccion = menu.mostrarMenu();

    // Inicia el juego en su respectivo Escenario
    if (seleccion >= 1 && seleccion <= 3) {
        /*
        Simulador simulador;
        simulador.setEscenario(seleccion);
        simulador.ejecutar();
        */
        if (seleccion == 1)
        {
            std::cerr << "Se ejecuto el escenario numero uno";
        }
        else if (seleccion == 2) {
            std::cerr << "Se ejecuto el escenario numero dos";
        }
        else if (seleccion == 3) {
            std::cerr << "Se ejecuto el escenario numero tres";
        }
    }

    return 0;
}
