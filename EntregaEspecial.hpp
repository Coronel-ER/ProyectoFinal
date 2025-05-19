#ifndef ENTREGA_ESPECIAL_HPP
#define ENTREGA_ESPECIAL_HPP

#include "Entrega.hpp"

class EntregaEspecial : public Entrega {
private:
    int bonoTiempo;

public:
    EntregaEspecial(const sf::Vector2f& pos, const std::string& destino, int bono);
    void entregar() override;
};

#endif
