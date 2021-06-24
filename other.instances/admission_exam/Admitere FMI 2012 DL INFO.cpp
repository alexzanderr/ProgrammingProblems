#include <iostream>
#include <fstream>

using namespace std;

#define en endl

int main() {

	// punctul a
	int xn[100000] = { 0 };
	int index = 1;

	bool exit = false;
	int n, x = 1, size = 0;
	cin >> n;

	for (int size = 0; size < n;) {

		for (int iter = 0; iter < x; iter++) {
			xn[index++] = x;
			cout << x << ' ';
			size++;
			if (size == n) {
				exit = true;
				break;
			}
		}
		if (exit) {
			break;
		}
		x++;
	}

	// Descrierea informala a detaliilor:
	/*
		Am utilizat un algoritm cu o complexitate patratica O(n^2) care utilizeaza 6 variabile, 4 de tip int si 
		1 de tip bool.
		Programul parcurge cu variabile size de la 0 pana la n si in acelasi timp cu variabila iter de la 0 la x 
		printeaza toate valorile x de x ori, in interiorul buclei se incrementeaza size si daca este egal cu n
		variabila exit se face true, adica pot iesi din bucla, iar dupa for daca exit este true atunci ies de tot din 
		toate buclele daca nu executia se continua si x se intcrementeaza cu postfixare.
	*/


	//punctul b


	// k este termenul efectiv al sirului


	n = n * 8;
	n++;
	double delta = n;

	double k = (-1 + sqrt(delta)) / 2.0;

	if (k == (int)k) {
		cout << k;
	}
	else {
		cout << int(k) + 1;
	}


	// Descrierea informala a detaliilor:
	/*
		Am utilizat un algoritm cu o complexitate constanta care utilizeaza 3 variabile: n, k si delta una de tip int
		si doua de tip double.
		Programul rezolva ecutia k^2 + k - 2*n = 0  calculand delta si valoarea k
		daca k este intreg atunci al n-lea termen este k, altfel al n-lea termen este parte intreaga de k + 1.
	*/


	//punctul c si d in acelasi timp datorita inteligentei

	int vx[10000] = { 0 };
	int vy[10000] = { 0 };

	for (size_t iter = 1; iter <= n; iter++) {
		vx[xn[iter]]++;
	}


	for (size_t iter = 1; iter <= n; iter++) {
		cout << vx[iter] << " ";
	}

	cout << en;


	ifstream read("numere.txt");


	int yn[100000] = { 0 };

	for (size_t iter = 1; iter <= n; iter++) {
		read >> yn[iter];
		vy[yn[iter]]++;
	}


	for (size_t iter = 1; iter <= n; iter++) {
		cout << vy[iter] << " ";
	}
	cout << en;
	
	bool egal = true; // pp ca sunt egali

	for (size_t iter = 1; iter <= n; iter++) {
		if (vx[iter] != vy[iter]) {
			egal = false;
		}
	}

	if (egal) {
		cout << "DA";
	}
	else {
		cout << "NU";
	}

	// Descrierea informala a detaliilor:
	/*
		Am construit un algoritm cu o complexitate liniara O(n) care 5 variabile de tip tablou: una fiind sirul x, 
		una fiind sirul yn citit, una de tip bool pentru existenta permutarii sirului yn
		si celelalte 2 fiind 2 vectori de frecventa pentru x si yn. 
		Citesc yn de la tastatura si construisc in acelasi timp vectorul de frecventa pentru acesta. Apoi parcurg
		de la 1 la n ambii vectori de frecventa in acelasi timp si daca unul dintre valori difera egal se face false,
		daca nu, ramane true dupa cum a fost initializat.
		La final, daca egal este true afisez "DA", altfel "NU", in caz contrar.
	*/

	// complexitate O(n) - liniara

	return 0;
}

