#include <iostream>

using namespace std;

// punctul a
void flip(int n, int v[], int i, int j) {
	i--;
	j--;
	while (i < j) {
		int aux = v[i];
		v[i] = v[j];
		v[j] = aux;
		i++;
		j--;
	}
}


//punctul b
void sortare_flip(int n, int v[]) {

	for (size_t iter = 0; iter < n; iter++) {

		int max = 0;
		int pozMax = v[0];

		for (size_t jiter = 1; jiter < n - iter; jiter++)
			if (max < v[jiter]) {
				max = v[jiter];
				pozMax = jiter;
			}

		flip(n, v, 1, pozMax + 1);
		flip(n, v, 1, n - iter);
	}

}

void divide_flip(int n, int v[], int i, int j) {

	if (j - i == 1)
		return;

	divide_flip(n, v, i, (i + j) / 2);
	divide_flip(n, v, (i + j) / 2 + 1, j);

	if (v[i - 1] < v[j - 1]) {
		if (v[i - 1] > v[(i + j) / 2 - 1])
			flip(n, v, i, (i + j) / 2);
		if (v[(i + j) / 2] > v[j - 1])
			flip(n, v, (i + j) / 2 + 1, j);
	}
	else {
		if (v[i - 1] < v[(i + j) / 2 - 1])
			flip(n, v, i, (i + j) / 2);
		if (v[(i + j) / 2] < v[j - 1])
			flip(n, v, (i + j) / 2 + 1, j);
	}

}

int main() {
	// FLIP master
	int v[16] = { 14, 13, 15, 16, 11, 12, 9, 10, 2, 1, 4, 3, 8, 7, 6, 5};
	int n = 16;
	divide_flip(n, v, 1, n);
	if (v[0] > v[n - 1])
		flip(n, v, 1, n);
	// print tablou
	for(int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}

	return 0;
}

