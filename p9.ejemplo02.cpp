#include <iostream>
#include <map>

using namespace std;

enum DiasSemana { lunes, martes, miercoles, jueves, viernes, sabado, domingo };

typedef map <DiasSemana, map <char, float>> MiTipoTabla;

int main () {
	MiTipoTabla t;
	DiasSemana d;
	char c;

	// Inicialización:
	// Ojo: Los operadores ++ y –– no están definidos para enumerados.
	
	for (d = lunes; d <= domingo; d = DiasSemana (d+1)) {
		for (c = 'a'; c <= 'z'; c++) {
			t[d][c] = 0.0;
		}
	}
	
	for (d = lunes; d <= domingo; d = DiasSemana (d+1)) {
		for (c = 'a'; c <= 'z'; c++) {
			if ((d == martes) && (c >= 'h') && (c <= 'k'))
					t[d][c]++;
		}
	}
	
	//Imprimir matriz
	for (c = 'a'; c <= 'z'; c++) {
		cout << c << " ";
	}
	cout << endl;
	for (d = lunes; d <= domingo; d = DiasSemana (d+1)) {
		for (c = 'a'; c <= 'z'; c++) {
			cout << t[d][c] << " ";
		}
		cout << endl;
	}
}
