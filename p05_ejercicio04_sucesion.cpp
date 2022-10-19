#include <iostream>

using namespace std;

int main(){
	/* Lexico */
	int an, a2, a1, a0, i, m;
	a0=1;
	a1=2;
	a2=3;
	m=0;
	/* Algoritmo */
	do {
		cout << "introduza el valor de m ";
		cin >> m;
	} while (m < 0);
	
	i=0;
	do {
		if (i>3){
			a0 = a1;
			a1 = a2;
			a2 = an;
		}
		switch(i){
			case 0:
				an = 1;
				break;
			case 1:
				an = 2;
				break;
			case 2:
				an = 3;
				break;
			default:
			    an = (3*a2) - (2*a0);
			    break;
		}
		cout << "a(" << i << ")=" << an << endl;
		i++;
	} while (an <= m);
}
