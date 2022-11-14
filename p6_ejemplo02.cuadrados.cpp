
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;
const char MARCA_FIN_LINEA = '\n';

void guardarFicheroInt (list<int> S, string nombre) {
	ofstream f;
	list<int>::iterator EA;

	f.open (nombre);
	if (!f) {
		cout << "Error abriendo el fichero resultado" << endl;
	}
	else
	{
		EA = S.begin();
		while (EA != S.end()) {
			f << *EA << " ";
			EA++;
		}//end-while
		f.close();
	}
};

void cargarFicheroInt (list<int> &S, string nombre) {
	ifstream f;
    int dato;
    
	f.open (nombre);
	if (!f) {
		cout << "Error abriendo el fichero de datos" << endl;
	}
	else {
		S.clear(); // Borra el contenido previo de la lista
		while (f >> dato) {
			S.push_back (dato);
		}
		f.close();
	}//end-if
};

int main()
{
	
	list<int> S, R;
	list<int>::iterator EA;
	int cuadrado;
	int suma;
	
	cout << "Cargando fichero" << endl;
	cargarFicheroInt (S, "entrada2.txt");
	cuadrado = 0;
	suma = 0;
	/* Primer esquema de recorrido del primer modelo de acceso secuencial*/
	EA = S.begin();
	while (EA != S.end()) {
		cout << *EA << " ";
		cuadrado = (*EA) * (*EA);
		suma = suma + cuadrado;
		R.push_back (cuadrado); 
		EA++;
	}//end-while
	R.push_back (suma); 
	guardarFicheroInt (R, "salida2.txt");
	cout << endl;
	cout << "Fichero salvado " << endl;
	cout << "La suma de lo procesado es " << suma << endl; 
	return 0;
}
