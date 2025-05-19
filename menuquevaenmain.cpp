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
