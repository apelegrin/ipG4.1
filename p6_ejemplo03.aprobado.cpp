
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;
const char MARCA_FIN_LINEA = '\n';

void guardarFicheroFloat (list<float> S, string nombre) {
	ofstream f;
	list<float>::iterator EA;

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

void cargarFicheroFloat (list<float> &S, string nombre) {
	ifstream f;
    float dato;
    
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
	
	list<float> S;
	list<float>::iterator EA;
	int numeroAprobados;
	int numeroAlumnos;
	float sumaCalificaciones;
	float mediaAlumnos;
	float maxCalificacion;
	float minCalificacion;
	
	cout << "Cargando fichero" << endl;
	cargarFicheroFloat (S, "entrada3.txt");
	numeroAprobados = 0;
	numeroAlumnos = 0;
	sumaCalificaciones = 0;
	mediaAlumnos = 0;
	maxCalificacion = 0;
	minCalificacion = 99;
	/* Primer esquema de recorrido del primer modelo de acceso secuencial*/
	EA = S.begin();
	while (EA != S.end()) {
		cout << *EA << " ";
		if (*EA >= 5.0){
			numeroAprobados++;
		}
		if ((*EA) > maxCalificacion) {
			maxCalificacion = *EA;
		}
		if ((*EA) < minCalificacion) {
			minCalificacion = *EA;
		}
		sumaCalificaciones = sumaCalificaciones + *EA;	
		numeroAlumnos++;
		EA++;
	}//end-while
	cout << endl;
	cout << "El número de aprobados es " << numeroAprobados << endl; 
	mediaAlumnos = sumaCalificaciones / numeroAlumnos;
	cout << "La media de las calificaciones es " << mediaAlumnos << endl; 
	cout << "La calificación máxima es " << maxCalificacion << endl; 
	cout << "La calificación mínima es " << minCalificacion << endl; 
	return 0;
}
