#include <iostream>
#include <cmath>

using namespace std;

bool esPrimo(int p,int &coste){
	bool primo;
	int i;
	float ra;
	
	if ((p == 1) || (p == 2)) {
		primo = true;
	}
	else if ((p % 2) == 0){
		primo = false;
	}
	else {
		i = 3;
		ra = sqrt(p);
		while ( ((p % i) != 0) && (i<= ra)) {
			i++;
			coste++;
		}
		if ((p % i) == 0){
			primo = false;
		}
		else {
			primo = true;
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
