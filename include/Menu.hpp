#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Menu {
private:
    sf::RenderWindow& window;
    sf::Font& font;
    sf::Font& TitleFont;

    std::vector<std::string> opciones;
    std::vector<sf::Text*> textos;

    int seleccion;

public:
    Menu(sf::RenderWindow& window, sf::Font& font, sf::Font& TitleFont);
    ~Menu();

    int mostrarMenu();
};

#endif
