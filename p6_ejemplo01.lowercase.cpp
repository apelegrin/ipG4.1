
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;
const char MARCA_FIN_LINEA = '\n';

void guardarFicheroChar (list<char> S, string nombre) {
	ofstream f;
	list<char>::iterator EA;

	f.open (nombre);
	if (!f) {
		cout << "Error abriendo el fichero resultado" << endl;
	}
	else
	{
		EA = S.begin();
		while (EA != S.end()) {
			if (*EA == MARCA_FIN_LINEA) {
				f << endl;
			} else {
				f << *EA;
			}
			EA++;
		}//end-while
		f.close();
	}
};

void cargarFicheroChar (list<char> &S, string nombre) {
	ifstream f;
	string cadena;
	int i;

	f.open (nombre);
	if (!f) {
		cout << "Error abriendo el fichero de datos" << endl;
	}
	else {
		S.clear(); // Borra el contenido previo de la lista
		while (getline(f, cadena)) {
			for (i=0; i<cadena.length(); i++) {
				S.push_back (cadena[i]);
			}
		S.push_back (MARCA_FIN_LINEA);
		}//end-while
		f.close();
	}//end-if
};

int main()
{
	/* Distancia entre los juegos de caracteres mayúsculas y minúsculas: */
	const int Distancia = int('a') - int('A');
	
	list<char> S, R;
	list<char>::iterator EA;
	char cConv;
	cout << "Cargando fichero" << endl;
	cargarFicheroChar (S, "salida1.txt");
	/* Primer esquema de recorrido del primer modelo de acceso secuencial*/
	EA = S.begin();
	while (EA != S.end()) {
		if ((*EA >= 'A') && (*EA <= 'Z')) {
			cConv = char(int(*EA) + Distancia);
		}
		else {
			cConv = *EA;
		}
		R.push_back (cConv); /* Registrar(R, c_conv) */
		EA++;
	}//end-while
	guardarFicheroChar (R, "salida1.1.txt");
	cout << "Fichero salvado " << endl;
	return 0;
}
