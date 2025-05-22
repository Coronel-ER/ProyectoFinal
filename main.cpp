#include <iostream>
#include <SFML/Graphics.hpp>
#include "Simulador.hpp"


// Pendiente Crear Clase Menu

// Impresion del menu
int mostrarMenu(sf::RenderWindow& window, sf::Font& font, sf::Font& TitleFont) {
    // Arreglo de opciones
    std::vector<std::string> opciones = {
        "Iniciar Nivel 1",
        "Iniciar Nivel 2",
        "Iniciar Nivel 3",
        "Salir"
    };
   
    std::vector<sf::Text> textos;
    int seleccion = 0;

    // Impresion Titulo
    sf::Text titulo(TitleFont);
    titulo.setString("CETYSwings");
    titulo.setCharacterSize(65);
    titulo.setFillColor(sf::Color(20,225,20));
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
            if (event -> is <sf::Event::Closed>()){
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

        window.clear(sf::Color(0,0,0));
        window.draw(sprite);

        // Impresion del titulo
        window.draw(titulo);

        //Impresion del texto
        for (size_t i = 0; i < textos.size(); ++i) {
            // Efecto Hover
            if (i == seleccion)
                textos[i].setFillColor(sf::Color::Yellow);
            else
                textos[i].setFillColor(sf::Color::Black);
            window.draw(textos[i]);
        }


        window.display();
    }

    return 4;
}

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

    // Impresion del menu regresa la opcion seleccionada
    int seleccion = mostrarMenu(window, font, TitleFont);

    // Inicia el juego en su respectivo nivel
    if (seleccion >= 1 && seleccion <= 3) {
        
        /*
        Simulador simulador;
        simulador.setNivel(seleccion);
        simulador.ejecutar();
        */
    }

    return 0;
}
