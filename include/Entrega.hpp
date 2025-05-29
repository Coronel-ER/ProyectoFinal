#ifndef ENTREGA_HPP
#define ENTREGA_HPP

#include <SFML/Graphics.hpp>
#include <string>


class Entrega {
protected:
    sf::Vector2f posicion;
    bool entregada;
    std::string nombreZona;
    int puntos;
    sf::CircleShape figura; // Representación gráfica simple

public:
    // Constructor
    Entrega(sf::Vector2f pos, const std::string& nombre);

    // Destructor virtual (para herencia segura)
    virtual ~Entrega();

    // Dibuja la entrega (polimorfismo dinámico)
    virtual void dibujar(sf::RenderWindow& ventana);

    // Marca la entrega como realizada
    virtual void entregar();

    // Consultas
    virtual bool estaEntregada() const;
    virtual sf::Vector2f getPosicion() const;
    virtual int getPuntos() const;
};

/*
 * Clase derivada EntregaEspecial: entrega con bono extra.
 * Sobrescribe métodos virtuales para comportamiento especializado.
 */
class EntregaEspecial : public Entrega {
private:
    int bono;

public:
    EntregaEspecial(sf::Vector2f pos, const std::string& nombre, int bono);

    virtual ~EntregaEspecial();

    virtual void dibujar(sf::RenderWindow& ventana) override;
    virtual void entregar() override;
    virtual int getPuntos() const override;
};

#endif
