#include <iostream>
#include <fstream>
using namespace std;

int matrice_adiac[1005][1005];
int vizitati[1005];

void print_matrice(int matrice[][1005], int dim) {
	for (int i = 1; i <= dim; i++) {
		for (int j = 1; j <= dim; j++) {
			cout << matrice[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;
}

void print_vizitati(int viz[1005], int dim) {
	for(int i = 1; i <= dim; i++) {
		cout << viz[i] << " ";
	}
	cout << endl;
}

void depth_first_search(int node, int dim) {
	vizitati[node] = 1;
	for (int i = 1; i <= dim; i++) {
		if (matrice_adiac[node][i] && !vizitati[i]) {
			depth_first_search(i, dim);
		}
	}
	
}

int main() {
	ifstream in("dfs.in");
	ofstream out("dfs.out");

	int n, m;
	in >> n >> m;

	for (int i = 0; i < m; ++i) {
		int x, y;
		in >> x >> y;
		matrice_adiac[x][y] = matrice_adiac[y][x] = 1;
	}

	int comp_conexe = 0;

	//print_matrice(matrice_adiac, n);
	for(int i = 1; i <= n; i++) {
		if(!vizitati[i]) {
			comp_conexe++;
			depth_first_search(i, n);
		}
	}
	
	out << comp_conexe;
	return 0;
}
