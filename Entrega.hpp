#ifndef ENTREGA_HPP
#define ENTREGA_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

/*
 * Clase base Entrega
 * - Representa un punto de entrega con posición, estado y puntos.
 * - Encapsula atributos privados/protegidos con acceso controlado.
 * - Implementa métodos virtuales para permitir polimorfismo.
 * - Incluye funcionalidad para mostrar información (debug) y estado.
 */
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

    // Dibuja la entrega en ventana (polimórfico)
    virtual void dibujar(sf::RenderWindow& ventana);

    // Marca la entrega como realizada y actualiza estado visual
    virtual void entregar();

    // Getters controlados
    virtual bool estaEntregada() const;
    virtual sf::Vector2f getPosicion() const;
    virtual int getPuntos() const;
    virtual std::string getNombreZona() const;

    // Método para debug o log que muestra estado completo
    virtual void mostrarInfo() const;
};

/*
 * Clase derivada EntregaEspecial
 * - Extiende Entrega con bono extra de puntos.
 * - Cambia apariencia visual para distinguirla.
 * - Puede incluir funcionalidades extra (por ejemplo, tiempo límite).
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

    // Nuevo método para obtener bono específico
    int getBono() const;

    virtual void mostrarInfo() const override;
};

#endif


#endif
