#include <iostream>
#include <vector>
#include "juego.hpp"
#include <string>

using namespace std;


class Entrega {
protected:
	vector<int> posicion;
	string localizacion;
	bool entregado;
	Usuario puntuacion;
public:
	Entrega(vector<int> posicion, string localizacion, bool entregado) : posicion(posicion), localizacion(localizacion), entregado(entregado){}

	virtual void Entregas() {
		if (entregado == true) {
			cout << "La entrega ha sido completada exitosamente \n";
			puntuacion = puntuacion + 1000;
		}
	}
	virtual ~Entrega() {}
};
