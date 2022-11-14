
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

#include "Secuencias.cpp"

struct Partido {
	int juegos1;
	int juegos2;
	int parcial1;
	int parcial2;
};

void imprimirParcial(int parcial){
	switch (parcial) {
		case 0:
			cout << " nada ";
			break;
		case 1:
			cout << " quince ";
			break;			
		case 2:
			cout << " treinta ";
			break;			
		case 3:
			cout << " cuarenta ";
			break;			
	}	
}

void marcador(char punto, Partido &partido){
	if (punto == '1'){
		partido.parcial1++;
		cout << "Punto para el jugador 1 "<< endl;
	}
	else if (punto == '2'){
		partido.parcial2++;
		cout << "Punto para el jugador 2 "<< endl;
	}
	/* si > 40 anotamos el juego al 1 */
	if (partido.parcial1 > 3) {
		partido.juegos1++;
		partido.parcial1 = 0;
		partido.parcial2 = 0;
		cout << "Juego para el jugador 1 "<< endl;
		cout << endl;
	}	
	else if (partido.parcial2 > 3) {
		partido.juegos2++;
		partido.parcial1 = 0;
		partido.parcial2 = 0;
		cout << "Juego para el jugador 2 "<< endl;
		cout << endl;
	}
	else {
		imprimirParcial(partido.parcial1);
		cout << " a ";
		imprimirParcial(partido.parcial2);
		cout << endl;
	}
}

int main()
{
	list<char> S;
	list<char>::iterator EA;
	Partido miPartido;
	char punto;
	
	/* Primer esquema de recorrido del primer 
	 * modelo de acceso secuencial */
	cargarFichero(S,"entrada6.txt");
	
	/* Inicializamos las variables */
	miPartido.juegos1  = 0;
	miPartido.juegos2  = 0;
	miPartido.parcial1 = 0;
	miPartido.parcial2 = 0;
	
	EA = S.begin();
	while (EA != S.end()){
			/* Procesar*/
			punto = *EA;
			cout << punto << endl;
			if ((punto == '1') || (punto == '2')){
				marcador(punto,miPartido);
			}
			/* Avanzar */
			EA++;
	}//end-while
	/* Procesado posterior */
	
	return 0;
}



