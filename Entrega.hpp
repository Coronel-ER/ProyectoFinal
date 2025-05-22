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
public:
	Entrega(vector<int> posicion, string localizacion, bool entregado) : posicion(posicion), localizacion(localizacion), entregado(entregado){}

	virtual void Entregas() {
		if (entregado == true) {
			cout << "La entrega ha sido completada exitosamente, +1000 puntos \n";
			subirPuntuacion(1000);
		}
	}
	virtual ~Entrega() {cout << "Entrega ha sido eliminada \n" }
};
