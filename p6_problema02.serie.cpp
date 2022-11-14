
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

#include "Secuencias.cpp"

int main()
{
	list<int> S;
	list<int> R;
	list<int> T;
	list<int>::iterator EA_S;
	list<int>::iterator EA_R;
	int h1,h2;	
	/* Primer esquema de recorrido del primer 
	 * modelo de acceso secuencial */
	cargarFichero(S,"entrada5_1.txt");
	cargarFichero(R,"entrada5_2.txt");
	
	/* Inicializamos las variables */
	T.clear();
	
	EA_S = S.begin();
	EA_R = R.begin();
	
	while ( (EA_S != S.end()) && (EA_R != R.end()) ){
		h1 = *EA_S;
		h2 = *EA_R;
		/* si coinciden salvamos la salida y avanzamos ambos */
		if (h1 == h2) {
			T.push_back(h1);
			cout << h1 << " ",
			EA_S++;
			EA_R++;
		}
		/* Avanzamos la menor */
		else if (h1 > h2) {
			EA_R++;
		}
		else {
			EA_S++;
		}	
		
	}//end-while
	/* Procesado posterior */
	guardarFichero(T,"salida5.txt");	
	return 0;
}



