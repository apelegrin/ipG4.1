#include <iostream>
#include <fstream>

using namespace std;

const int N = 20;
const int NFilas = N; /* constante con el número de filas */
const int NColumnas = N; /* constante con el número de columnas */

typedef int Matriz[NFilas][NColumnas];

void cargarFichero (Matriz &S, int &NF, int &NC, string nombre) {
	ifstream f;
	int i, j;
	f.open (nombre);
	if (!f)
		cout << "Error abriendo el fichero" << endl;
	else {
	f >> NF;
	f >> NC;
		for (i=0; i < NF; i++) {
			for (j=0; j < NC; j++) {
				f >> S[i][j];
			}
		}
	}
	f.close();
}

void mostrarTabla(Matriz t, int nf, int nc){
	int i, j;
	int aa = 1990;
	/* Encabezados */
	cout << "     ";
	for (j = 0; j < nc; ++j) {
		cout << " G." << j ;
	}
	cout << endl;
	for (i = 0; i < nf; ++i) {
		cout << aa <<"|";
		aa++;
		for (j = 0; j < nc; ++j) {
			if (t[i][j] < 100){
				cout << "  " << t[i][j];
			}
			else{
				cout << " " << t[i][j];
			}
		}
		cout << endl;
	}
}

int buscarAnoMayorEgresados(Matriz t,int nf,int nc){
	int maxAlumnos = 0;
	int aaMaxAlumnos = -1;
	int sum;
	
	for (int i=0; i < nf; i++) {
		sum = 0;
		for (int j=0; j < nc; j++) {
			sum = sum + t[i][j];
		}
		if (sum > maxAlumnos){
			maxAlumnos = sum;
			aaMaxAlumnos = i;
		}
	}
	return aaMaxAlumnos;
}

int buscarGradoMinEgresados(Matriz t,int nf,int nc){
	int minAlumnos = 99999;
	int gradoMinAlumnos = 0;
	int sum;
	
	for (int j=0; j < nc; j++)  {
		sum = 0;
		for (int i=0; i < nf; i++) {
			sum = sum + t[i][j];
		}
		if (sum < minAlumnos){
			minAlumnos = sum;
			gradoMinAlumnos = j;
		}
	}
	return gradoMinAlumnos;
}

int buscarGradoProEgresados(Matriz t,int nf,int nc){
	bool aumento = false;
	int i,j;
	
	j=0;
	while ((j < nc) && (!aumento)){
		i=1;
		while ( (i < nf) && (t[i][j] > t[i-1][j]) ){
			i++;
		}
		if (i==nf){
		   aumento = true;
		}
		j++;
	}	
	if (aumento)
	   return j-1;
	else
	   return -1;	
}		

int main () {
	/* Lexico */
	Matriz t;
	int nf,nc;
	int anoMayorEgresados;
	int gradoMinEgresados;
	int gradoAumenta;
	
	cargarFichero(t,nf,nc,"egresados.txt");
	mostrarTabla(t,nf,nc);
	
	anoMayorEgresados = 1990+buscarAnoMayorEgresados(t,nf,nc);
	cout << "El año con mayor número de egresados fue "<<anoMayorEgresados<<endl;
	gradoMinEgresados = buscarGradoMinEgresados(t,nf,nc);
	cout << "El grado con memor número de egresados fue G."<<gradoMinEgresados<<endl;
	gradoAumenta = buscarGradoProEgresados(t,nf,nc);
	cout << "El grado que aumenta egresados fue G."<<gradoAumenta<<endl;
}
