#ifndef ENTREGA_ESPECIAL_HPP
#define ENTREGA_ESPECIAL_HPP

#include "Entrega.hpp"

class EntregaEspecial : public Entrega {
private:
    int bonoTiempo; // por ejemplo, recompensa adicional por entregar rápido

public:
    EntregaEspecial(const sf::Vector2f& pos, const std::string& destino, int bono);
    void entregar() override;
};

#endif
