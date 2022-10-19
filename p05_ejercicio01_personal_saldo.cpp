#include <iostream>

using namespace std;

float interesMensual(float saldo,float inte){
	int valor;
	valor = 0;
	valor = saldo * (inte / 100) /12;
	return valor;
};

int main(){
	/* Lexico */
	const float CANTIDAD_INICIAL = 125;
	const float APORTA = 180;
	int m, meses;
	float saldo;
	
	/* Algoritmo */
	m=0;
	meses = 0;
	saldo=CANTIDAD_INICIAL;
	cout << "Introduce la cantidad a ahorrar ";
	cin >> m;
	while (saldo < m){
		saldo = saldo + interesMensual(saldo,4) + APORTA;
		meses++;
	}
	cout << "necesitas " << meses << " años" << meses/12;
}
