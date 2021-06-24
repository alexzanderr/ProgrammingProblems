#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#define en endl

void printv(int* v, int n) {
	for (size_t iter = 0; iter < n; iter++) {
		cout << v[iter] << " ";
	}
	cout << en;
}

void print(int x, int y) {
	cout << '(' << x << ',' << y << ") ";
}

void delette(int* v, int start, int& size, int k) {
	cout << '(' << k << ' ' << v[start] << ") ->>    ";
	for (size_t iter = start; iter < size - 1; iter++) {
		v[iter] = v[iter + 1];
	}
	size--;
	printv(v, size);
}

int main() {

	// punctul a

	//int n, p;
	//cin >> n >> p;

	//int m = pow(2, n);
	//int v[100000] = { 0 };

	//for (size_t iter = 0; iter < m + 2; iter++) {
	//	v[iter] = iter;
	//}

	//v[0] = -1;
	//v[p] = -1;
	//v[m + 1] = -1;

	//int poz = 1;
	// vectorul 0 1 2 3 4 5 6 7 8 9 
	//          x x x x x x x x x x
	//for (size_t k = 1; k <= n; k++) {
	//	int nrelem = pow(2, k - 1);
	//	for (size_t e = 1; e <= nrelem; e++) {
	//		if (v[poz] != -1) {
	//			v[poz] = -1;
	//			print(k, poz);
	//			poz++;
	//		}
	//		else {
	//			poz++;
	//			v[poz] = -1;
	//			print(k, poz);
	//			poz++;
	//		}
	//	} // dupa pasul k
	//}
	//cout << en;
	//printv(v, m + 2);

	//	(k, poz)
	// exemplu 
	/*
		k = 1 (1,1)
		k = 2 (2,2) (2,3)
		k = 3 (3,4) (3,6) (3,7) (3,8)
	*/



	// punctul b

	// 0 1 2 .............. m, m + 1
	// m + 2 elemente


	int n, p;
	cin >> n >> p;

	int m = pow(2, n);
	int v[100000] = { 0 };


	int max = m / 2;
	m += 2;
	for (size_t iter = 0; iter < m; iter++) {
		v[iter] = iter;
	} //reinitializare

	delette(v, p, m, 0);
	delette(v, 0, m, 0);
	m--;
	int k = 1;
	while (k <= n) {
		int lung = 1;
		for (size_t iter = 0; iter < m; iter++) {
			if (v[iter] + 1 == v[iter + 1]) {
				lung++;
			}
			if (v[iter] + 1 != v[iter + 1] || iter == m - 1) {
				if (lung >= max) {
					if (lung > 1) {
						delette(v, (2 * iter - lung) / 2, m, k);
						lung = 1;
					}
					if (max == 1) {
						delette(v, iter, m, k);
						iter--;
					}
				}

			}
		}
		k++;
		max /= 2;
	}



	// Complexitatea algoritmului este O(n)

	// vectorul 0 1 2 3 4 5 6 7 8 9 
	//          x x x x x x x x x x





	return  0;
}

