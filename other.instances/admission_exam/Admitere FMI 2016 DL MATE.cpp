#include <iostream>

using namespace std;

bool Prim(int x) {
	if (x == 1)
		return true;
	if (x < 2)
		return false;
	else if (x > 2 && x % 2 == 0)
		return false;
	else
		for (size_t iter = 3; iter * iter <= x; iter += 2)
			if (x % iter == 0)
				return false;
	return true;
}

void PrintVector(int* v, int n) {
	for (size_t iter = 1; iter <= n; iter++)
		cout << v[iter] << ' ';
	cout << '\n';
}


// 1 2 3 4 5 0 0 0 0 0
// 5 5 5 5 5


bool ExistaElemente(int* v, int n) {
	for (size_t iter = 1; iter <= n; iter++)
		if (v[iter] != 0)
			return true;
	return false;
}

void DeleteElement(int* v, int index, int& n) {
	for (size_t iter = index; iter <= n; iter++) {
		v[iter] = v[iter + 1];
	}
	n--;
	PrintVector(v, n);
}

int main() {

	int v[1000] = { 0 };
	int deleted[1000] = { 0 };
	int nrdeleted = 0;
	int remain[1000] = { 0 };
	int prime[1000] = { 0 };
	int index = 0;
	int n = 10;
	int initialn = n;

	for (size_t iter = 1; iter <= n; iter++) {
		if (Prim(iter)) {
			prime[iter] = 1;
		}
		v[iter] = iter;
	}


	while (true) {
		int nrremain = 0;
		if (n <= 3) {
			for (size_t iter = 1; iter <= n; iter++) {
				deleted[++nrdeleted] = v[iter];
			}
			break;
		}
		for (size_t iter = 1; iter <= n; iter++) {
			if (prime[iter]) {
				deleted[++nrdeleted] = v[iter];
			}
			else {
				remain[++nrremain] = v[iter];
			}
		}
		for (size_t iter = 1; iter <= nrremain; iter++) {
			v[iter] = remain[iter];
		}
		n = nrremain;
	}

	for (size_t iter = 1; iter <= initialn; iter++) {
		cout << deleted[iter] << " ";
	}






	// incercarea lui alexandru andrew care din pacate a esuat


	/*for (int i = 0; i < 3; i++) {
		DeleteElement(v, 1, n);
		deleted[index++] = v[1];
	}

	bool continua = true;
	if (!ExistaElemente(v, n))
		continua = false;


	while (continua) {

		for (size_t iter = 1; iter <= n; iter++) {
			if (Prim(iter)) {
				deleted[index++] = v[iter];
				DeleteElement(v, iter, n);
			}
		}

		if (ExistaElemente(v, n)) {
			continua = true;
		}
		else {
			continua = false;
		}
	}




	PrintVector(v, n + 10);

	for (size_t iter = 0; iter < index; iter++) {
		cout << deleted[iter] << " ";
	}*/

	return 0;
}

