

#include <iostream>
#include <vector>
#include "juego.hpp"
#include <string>

using namespace std;

class EntregasEspeciales:: public Entrega {


public:
	EntregasEspeciales(vector<int> posicion, string localizacion, bool entregado) : Entrega(posicion, localizacion, entregado) {}


  
	void Entregas() override {
		if (entregado == true) {
			cout << "La entrega especial ha sido completada exitosamente +2000 puntos \n";
			subirPuntuacion(2000);
		}
	}
  ~EntregaEspeciales(){}

};
