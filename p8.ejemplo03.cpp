#include <iostream>

using namespace std;

#define TAM_HISTO 'Z' - 'A' + 1 // A=65 Z=90 90-65+1  =26
#define elemHisto(h,c) h[(c) - 'A'] // B=66 - 65 

int main() {
	
	int frecLetras[TAM_HISTO];
	
	frecLetras[1] = 66; //frecLetras['B']
	cout << "B aparece " << frecLetras[1] << endl;
	
	frecLetras['B'-'A'] = 50;
	cout << "B aparece " << frecLetras['B'-'A'] << endl;
	
	elemHisto(frecLetras,'B') = 33;
	cout << "B aparece " << elemHisto(frecLetras,'B') << endl;
	

}

