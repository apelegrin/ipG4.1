#include <iostream>
#include <fstream>
#include <list>
#include <map> 
#include <string>

using namespace std;

#include "Secuencias.cpp"

typedef map<char,int> TipoHistograma;
string pintaBarra(float p){
	string b="";
	float total = p*100/50;
	for (float i=0;i<total;i++){
		b=b+"*";
	}	
	return b;
}
int main (){
	/* Lexico */
	list<char> S;
	list<char>::iterator EA;
	TipoHistograma histograma;
	
	float nCaracteres;
	float p;
	string barra;
	
	barra = "";
	/* Inicializar el histograma a 0 */
	for (char c ='a'; c <= 'z'; c++){
		histograma[c]=0;
	}
	
	cargarFichero(S,"entrada8.1.txt");
	/* Esquema de recorrido del primer modelo de AS*/
	EA=S.begin();
	
	while (EA != S.end()){
		/* Tratamiento */
		cout << *EA;
		if ((*EA >= 'a') && (*EA <= 'z')){
			histograma[*EA]++;
			nCaracteres++;
		}
		/* Avanzar */
		EA++;
	}
	
	/* Imprimir histograma */
	for (char c ='a'; c <= 'z'; c++){
		/* calculo el porcentaje*/
		p = histograma[c] * 100 / nCaracteres;
		barra = pintaBarra(p);
		cout << c << " ->"<<histograma[c] << " - " << barra << endl;
	}
	cout << "El texto tiene " << nCaracteres << " letras" << endl;
}







