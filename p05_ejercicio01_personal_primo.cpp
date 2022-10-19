#include <iostream>

using namespace std;

bool esPrimo(int p,int &coste){
	bool primo;
	int i;
	
	if (p == 1) {
		primo = true;
	}
	else {
		i = 2;
		while ((p % i) != 0){
			i++;
			coste++;
		}
		if (p == i){
			primo = true;
		}
		else {
			primo = false;
		}
	}
	return primo;
}
int main(){
	/* Lexico */
	int coste;
	
	/* Algoritmo */
	coste = 0;
	for (int i = 0; i < 10000; i++){
		if (esPrimo(i,coste)){
			cout << i << " ";
		}
	}
	cout << endl;
	cout << "El coste del cálculo es " << coste;
}
