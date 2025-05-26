#include <iostream>
#include <vector>
#include <string>

using namespace std;

int puntajeTotal = 0;

class Entrega {
protected:
	vector<int> posicion;
	string localizacion;
	bool entregado;
public:
	Entrega(vector<int> posicion, string localizacion, bool entregado) : posicion(posicion), localizacion(localizacion), entregado(entregado) {}

	virtual void Entregas() {
		if (entregado == true) {
			cout << "La entrega ha sido completada exitosamente, +1000 puntos \n";
			puntajeEntrega(1000);
		}
	}
	void puntajeEntrega(int p) {
		puntajeTotal += p;
	}
	virtual ~Entrega() {}
};

class EntregasEspeciales: public Entrega {


public:
	EntregasEspeciales(vector<int> posicion, string localizacion, bool entregado) : Entrega(posicion, localizacion, entregado) {}

	void Entregas() override {
		if (entregado == true) {
			cout << "La entrega especial ha sido completada exitosamente +2000 puntos \n";
			puntajeEntrega(2000);
		}
	}

};
//main de prueba de las clases de entregas
int main() {
	//creacion de entregas
	Entrega entrega1({ 100, 400 }, "entrega normal true", true);
	Entrega entrega2({ 200, 600 }, "entrega normal false", true);
	EntregasEspeciales especial1({ 300, 500 }, "entrega especial false", false);
	EntregasEspeciales especial2({ 600, 200 }, "entrega especial true", true);

	//vector de punteros de entrega
	vector<Entrega*> listaEntregas = { &entrega1, &entrega2, &especial1, &especial2 };


	cout << "=== Simulador de Entregas ===" << endl;
	for (auto& entrega : listaEntregas) {
		entrega->Entregas();
	}


	cout << "Puntaje total: " << puntajeTotal << " puntos" << endl;


	return 0;
}
