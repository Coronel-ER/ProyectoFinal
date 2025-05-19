// usare arial.ttf porque la fuente predeterminada se ve muy fea y no nos gustó

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

// función que muestra el menú y regresa la opción seleccionada
int mostrarMenu(sf::RenderWindow& window, sf::Font& font) {
    std::vector<std::string> opciones = {
        "Iniciar Nivel 1",
        "Iniciar Nivel 2",
        "Iniciar Nivel 3",
        "Salir"
    };

    std::vector<sf::Text> textos;
    int seleccion = 0; // empezamos con la primera opción seleccionada

    // creamos los textos para cada opción del menú
    for (size_t i = 0; i < opciones.size(); ++i) {
        sf::Text texto(opciones[i], font, 30);
        texto.setPosition(250, 200 + i * 50); // las vamos bajando en Y
        textos.push_back(texto);
    }

    // loop para que el menú esté activo mientras no se cierre o se elija algo
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // si cierran la ventana, pues se cierra
                return 4;       // devolvemos 4 para indicar que se salió
            }
            // movemos la selección con las flechitas
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    seleccion = (seleccion - 1 + opciones.size()) % opciones.size(); // hacia arriba
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    seleccion = (seleccion + 1) % opciones.size(); // hacia abajo
                }
                else if (event.key.code == sf::Keyboard::Enter) {
                    return seleccion; // si le dan Enter, regresamos la opción elegida
                }
            }
        }

        // repintamos todo bonito
        window.clear(sf::Color(100, 149, 237)); // AZZZZZUL de fondo
        for (size_t i = 0; i < textos.size(); ++i) {
            if (i == seleccion)
                textos[i].setFillColor(sf::Color::Yellow); // resalta la opción actual
            else
                textos[i].setFillColor(sf::Color::White);  // las otras se ven normal
            window.draw(textos[i]); // dibujamos cada texto
        }
        window.display(); // actualizamos la pantalla
    }

    return 4; // si llega aquí es porque algo raro pasó, devolvemos opción salir por default
}
