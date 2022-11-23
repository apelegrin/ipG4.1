#include <iostream>
#include <map> 

using namespace std;

typedef map<char,int> TipoHistograma;

int main() {
	
	TipoHistograma histo;
	char op;
	
	for(char c='a'; c <= 'z'; c++){
		histo[c] = 0;
	}

	histo['k'] = 7;
	cout << "El valor del histo de k es " << histo['k'] << endl;
	op = 'k';
	histo[op]++;
	cout << "El valor del histo de k es " << histo['k'] << endl;
}

