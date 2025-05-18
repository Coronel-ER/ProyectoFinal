//usare arial.ttf por que la fuente predetermianda se ve muy fea y no nos gustp
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

int mostrarMenu(sf::RenderWindow& window, sf::Font& font) {
    std::vector<std::string> opciones = {
        "Iniciar Nivel 1",
        "Iniciar Nivel 2",
        "Iniciar Nivel 3",
        "Salir"
    };

    std::vector<sf::Text> textos;
    int seleccion = 0;

    for (size_t i = 0; i < opciones.size(); ++i) {
        sf::Text texto(opciones[i], font, 30);
        texto.setPosition(250, 200 + i * 50);
        textos.push_back(texto);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up)
                    seleccion = (seleccion + opciones.size() - 1) % opciones.size();
                if (event.key.code == sf::Keyboard::Down)
                    seleccion = (seleccion + 1) % opciones.size();
                if (event.key.code == sf::Keyboard::Enter)
                    return seleccion + 1;
            }
        }

        window.clear(sf::Color(100, 149, 237));
        for (size_t i = 0; i < textos.size(); ++i) {
            if (i == seleccion)
                textos[i].setFillColor(sf::Color::Yellow);
            else
                textos[i].setFillColor(sf::Color::White);
            window.draw(textos[i]);
        }
        window.display();
    }

    return 4; // por si cierra ventana
}
