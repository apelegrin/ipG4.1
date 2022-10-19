#include <iostream>

using namespace std;

void divisionEntera(int dividendo,int divisor,int &cociente, int &resto){
	resto = dividendo;
	while (resto >= divisor) {
		resto = resto - divisor;
		cociente++;
	}
}
-
int main(){
	/* Lexico */
	int dividendo, divisor, cociente, resto;
	
	/* Algoritmo */
	dividendo = 0;
	divisor = 0;
	do {
		cout << "introduza dividendo y divisor ";
		cin >> dividendo >> divisor;
	} while ((divisor <= 0) || (divisor > dividendo));
	cociente = 0;
	resto = 0;
	divisionEntera(dividendo,divisor,cociente,resto);
	cout << dividendo << " / " << divisor << " = " << cociente << endl;
	cout << dividendo << " = " << divisor * cociente + resto << endl;
}
