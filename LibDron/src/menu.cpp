#include "Menu.hpp"
#include <iostream>

Menu::Menu(sf::RenderWindow& window, sf::Font& font, sf::Font& TitleFont)
    : window(window), font(font), TitleFont(TitleFont), seleccion(0) {
    opciones = {
        "Iniciar Escenario 1",
        "Iniciar Escenario 2",
        "Iniciar Escenario 3",
        "Salir"
    };

    for (const auto& op : opciones) {
        sf::Text* texto = new sf::Text();
        texto->setFont(font);
        texto->setString(op);
        texto->setCharacterSize(30);
        texto->setStyle(sf::Text::Bold);
        texto->setFillColor(sf::Color::White);
        textos.push_back(texto);
    }
}

Menu::~Menu() {
    limpiarTextos();
}

void Menu::limpiarTextos() {
    for (auto t : textos) {
        delete t;
    }
    textos.clear();
}

int Menu::mostrarMenu() {
    sf::Text titulo(TitleFont);
    titulo.setString("CETYSwings");
    titulo.setCharacterSize(70);
    titulo.setFillColor(sf::Color(20, 225, 20));
    titulo.setStyle(sf::Text::Bold);
    titulo.setPosition({ (800.f - titulo.getLocalBounds().width) / 2, 80 });

    // Fondo con textura de menú
    sf::Texture texture;
    if (!texture.loadFromFile("recursos/MenuBG.png")) {
        window.clear(sf::Color(10, 10, 10)); // Fondo gris oscuro
    }
    else {
        sf::Sprite sprite(texture);
        window.clear();
        window.draw(sprite);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    seleccion = (seleccion + opciones.size() - 1) % opciones.size();
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    seleccion = (seleccion + 1) % opciones.size();
                }
                else if (event.key.code == sf::Keyboard::Enter) {
                    return seleccion + 1;
                }
            }
        }

        // Animación suave para la selección
        for (size_t i = 0; i < textos.size(); ++i) {
            textos[i]->setPosition({ (800.f - textos[i]->getLocalBounds().width) / 2, 250.f + i * 50 });
            textos[i]->setFillColor(i == seleccion ? sf::Color::Green : sf::Color::White);
            window.draw(*textos[i]);
        }

        // Animación de aparición de título (se mueve hacia abajo)
        if (titulo.getPosition().y < 80) {
            titulo.setPosition(titulo.getPosition().x, titulo.getPosition().y + 1);
        }

        window.draw(titulo);
        window.display();
    }

    return 4; // Si se cierra la ventana, salir
}
