#define juego.hpp todavia no existe

#include <SFML/Graphics.hpp>
#include "Dron.hpp"//no existe
#include "Entrega.hpp"//no esta terminada
#include "EntregaEspecial.hpp"// no existe
#include "Colisiones.hpp"
#include <vector>

class Juego {
private:
    sf::RenderWindow ventana;
    Dron dron;
    std::vector<Entrega> entregas;
    int nivelActual;

public:
    Juego();
    void ejecutar();
    void procesarEventos();
    void actualizar();
    void renderizar();
};
