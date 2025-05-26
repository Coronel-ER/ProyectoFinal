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
        textos.push_back(texto);
    }
}

Menu::~Menu() {
    for (auto t : textos) {
        delete t;
    }
    textos.clear();
}

int Menu::mostrarMenu() {
    sf::Text titulo(TitleFont);
    titulo.setString("CETYSwings");
    titulo.setCharacterSize(65);
    titulo.setFillColor(sf::Color(20, 225, 20));
    titulo.setPosition({ (800.f - titulo.getLocalBounds().width) / 2, 80 });

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

        sf::Texture texture;
        if (!texture.loadFromFile("recursos/MenuBG.png")) {
            window.clear(sf::Color::Black);
        }
        else {
            sf::Sprite sprite(texture);
            window.clear();
            window.draw(sprite);
        }

        window.draw(titulo);

        for (size_t i = 0; i < textos.size(); ++i) {
            textos[i]->setPosition({ (800.f - textos[i]->getLocalBounds().width) / 2, 250.f + i * 50 });
            textos[i]->setFillColor(i == seleccion ? sf::Color::Green : sf::Color::White);
            window.draw(*textos[i]);
        }

        window.display();
    }
    return 4;
}
