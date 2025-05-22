//Agregue setnivel y el ejecutar para que sirva con el menu
//tambien elimine lugares para que mejor por nivel
#include "Juego.hpp"
#include "Colisiones.hpp"
#include <iostream>

// constructor del juego: inicializa la ventana con título y tamaño, y asigna el nivel actual como 1
Juego::Juego() : ventana(sf::VideoMode(800, 600), "CETYSWings - Nivel"), nivelActual(1) {
    ventana.setFramerateLimit(60);
}
// método agregado para configurar el nivel del juego desde el menú
// dependiendo del número de nivel se cargan distintas entregas (normales o especiales)
void Juego::setNivel(int nivel) {
    nivelActual = nivel; // Guarda el nivel actual
    entregas.clear(); // Limpia las entregas anteriores para evitar duplicados
    
// configuración de entregas según el nivel seleccionado
    if (nivel == 1) {
        // Nivel 1 solo entregas normales
        entregas.push_back(new Entrega(sf::Vector2f(300, 100), "Zona Río"));
        entregas.push_back(new Entrega(sf::Vector2f(500, 200), "Playas"));
        entregas.push_back(new Entrega(sf::Vector2f(400, 300), "Zona Centro"));
        entregas.push_back(new Entrega(sf::Vector2f(200, 400), "La Presa"));
    } else if (nivel == 2) {
        // Nivel 2 mezcla de entregas normales y especiales
        entregas.push_back(new EntregaEspecial(sf::Vector2f(600, 300), "Otay", 10));
        entregas.push_back(new Entrega(sf::Vector2f(400, 250), "La Mesa"));
        entregas.push_back(new EntregaEspecial(sf::Vector2f(150, 350), "El Florido", 15));
        entregas.push_back(new Entrega(sf::Vector2f(300, 450), "5 y 10"));
    } else if (nivel == 3) {
        // Nivel 3 entregas con mayor dificultad y puntos especiales
        entregas.push_back(new EntregaEspecial(sf::Vector2f(150, 500), "CETYS Universidad", 20));
        entregas.push_back(new Entrega(sf::Vector2f(100, 100), "Zona Centro"));
        entregas.push_back(new EntregaEspecial(sf::Vector2f(600, 150), "Chapultepec", 25));
        entregas.push_back(new Entrega(sf::Vector2f(250, 350), "Club Campestre"));
    }
}
// método agregado que ejecuta el ciclo principal del juego (game loop)
// se mantiene activo mientras la ventana esté abierta
void Juego::ejecutar() {
    while (ventana.isOpen()) {
        procesarEventos(); // captura eventos como cerrar ventana o entrada del teclado
        actualizar(); // actualiza la lógica del juego, como entregar paquetes
        renderizar(); // dibuja todos los elementos en pantalla
    }
}

// captura y maneja los eventos de usuario
void Juego::procesarEventos() {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed) // si el usuario cierra la ventana, se cierra el juego
            ventana.close();
    }
    dron.mover(); // mueve el dron según entrada del jugador 
}

// actualiza la lógica del juego: verifica si el dron entrega un paquete
void Juego::actualizar() {
    for (auto& e : entregas) {
        // si la entrega no ha sido realizada y el dron colisiona con la posición de la entrega
        if (!e->estaEntregada() && Colisiones::detectar(dron.getSprite(), e->posicion)) {
            e->entregar();
        }
    }
}

// Dibuja todos los elementos en la ventana
void Juego::renderizar() {
    ventana.clear(sf::Color(102, 204, 102));
    for (auto& e : entregas)
        e->dibujar(ventana); // Dibuja cada entrega
    dron.dibujar(ventana); // Dibuja el dron
    ventana.display(); 
}
