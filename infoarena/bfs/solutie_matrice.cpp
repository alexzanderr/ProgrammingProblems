#include <iostream>
#include <fstream>
//#include "D:\__Alexzander_files__\__computer_science__\cplusplus_stuff\__graphs__\util.hpp"

using namespace std;

#define lim 1005

int vizitate[lim];
int matrice[lim][lim];
int n;
int m;
int nod_start;
int coada[lim];
int distante[lim];

void bfs(int nod) {
    /*
    distante[nod] = 0;
    vizitate[nod] = 1;
    int lungime = 1;
    coada[lungime] = nod;
    for(int i = 1; i <= lungime; i++) {
        for(int j = 1; j <= grade[coada[i]]; j++) {
            if (distante[matrice[coada[i]][j]] == -1) {
                coada[++lungime] = matrice[coada[i]][j];
                distante[coada[lungime]] = distante[coada[i]] + 1;
            }
        }
    }
    */

    //cout << "BFS: [ (" << nod << ") -> ";
    int start = 1;
    int stop = 1;
    vizitate[nod] = 1;
    coada[1] = nod;
    while (start <= stop) {
        int x = coada[start++];
        for(int i = 1; i <= n; i++) {
            if (matrice[x][i] && !vizitate[i]) {
                vizitate[i] = 1;
                coada[++stop] = i;
                distante[coada[stop]] = distante[x] + 1;
                //cout << i << " -> ";
            }
        }
    }
    //cout << "]\n" << endl;
    
}

void print_vizitate() {
    cout << "Vizitate: ";
    for(int i = 1; i <= n; i++) {
        cout << vizitate[i] << " ";
    }
    cout << "\n" << endl;
}

void print_distante() {
    cout << "Distante: ";
    for(int i = 1; i <= n; i++) {
        cout << distante[i] << " ";
    }
    cout << "\n" << endl;
}

int main() {
	ifstream input("bfs.in");
	ofstream output("bfs.out");

    input >> n >> m >> nod_start;
    for(int i = 0; i < m; i++) {
        int x;
        int y;
        input >> x >> y;
        matrice[x][y] = 1;
    }

    //PrintAdjacencyMatrix(matrice, n);
    //cout << '\n';
    bfs(nod_start);

    //print_grade();
    //print_vizitate();
    //print_distante();
    
    for(int i = 1; i <= n; i++) {
        if (i != nod_start && !distante[i]) {
            distante[i] = -1;
        }
    }
    
    //print_distante();

    for(int i = 1; i <= n; i++) {
        output << distante[i] << " ";
    }

	input.close();
	output.close();
	return 0;
}