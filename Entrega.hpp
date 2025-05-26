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
    sf::CircleShape figura;

public:
    Entrega(sf::Vector2f pos, const std::string& nombre);
    virtual ~Entrega();

    virtual void dibujar(sf::RenderWindow& ventana);
    virtual void entregar();

    virtual bool estaEntregada() const;
    virtual sf::Vector2f getPosicion() const;
    virtual int getPuntos() const;
};

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
