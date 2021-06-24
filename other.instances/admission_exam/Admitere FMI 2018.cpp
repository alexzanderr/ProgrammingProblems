#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include "Functii proiect.h"

using namespace std;

#define e '\n'
#define s ' '
#define t '\t'

typedef unsigned const int UCI;
typedef unsigned int UI;

UCI lim5 = 1e+5;
UCI lim3 = 1e+3;
UCI lim2 = 1e+2;

struct Coord {
	UI x;
	UI y;
	UI vizitat;
} coord[1000];

void CitireSir(char sir[lim5], UI &size) {
	char litera;
	do {
		litera = getchar();
		sir[size++] = litera;
	} while (litera != '\n');
	sir[--size] = 0;
}

void CreareCuvant(char sir[lim5], char cuv[lim3], UI start, UI &stop);

void AdaugaCuv(char text[lim2][lim2], char cuv[lim3], UI linie, UI start, UI stop, UI &inceput);

void PrintMatriceX(char text[][lim2], UI linie);

void PrintMatrice(char text[][lim2], UI linie) {
	for (size_t iter = 0; iter <= linie; iter++) {
		for (size_t jiter = 0; text[iter][jiter] != 0; jiter++) {
			cout << text[iter][jiter];
		}
		cout << e;
	}
}

void AlocareMatriceSpatii(int spatii[][lim2], char text[][lim2], UI linie) {
	for (size_t iter = 0; iter <= linie; iter++) {
		for (size_t jiter = 0; text[iter][jiter] != 0; jiter++) {
			if (text[iter][jiter] == s) {
				spatii[iter][jiter] = 1;
			}
		}
	}
}

void PrintMatriceSpatii(int spatii[][lim2], UI linie, UI coloana) {
	for (size_t iter = 0; iter <= linie; iter++) {
		for (size_t jiter = 0; jiter <= coloana; jiter++) {
			cout << spatii[iter][jiter];
		}
		cout << e;
	}
}

int ReturnColoana(char text[][lim2], UI linie) {
	UI maxCol = 0;

	size_t jiter = 0;
	for (size_t iter = 0; iter <= linie; iter++) {
		for (; text[iter][jiter] != 0; jiter++) {
		}
		if (jiter > maxCol) {
			maxCol = jiter;
		}
	}
	return maxCol;
}


int main()
{

	char sir[lim5] = { NULL };
	char cuv[lim3] = { NULL };
	char text[lim2][lim2] = { NULL };

	int spatii[lim2][lim2] = { 0 };

	UI L;
	UI size = 0;
	UI start = 0, stop;
	UI linie = 0;
	UI inceput = 0;

	bool flag = false;

	cin >> L;
	UI LL = L;

	CitireSir(sir, size);

	do
	{
		CreareCuvant(sir, cuv, start, stop);

		if ((stop - start) <= LL) {
			cout << cuv;

			AdaugaCuv(text, cuv, linie, start, stop, inceput);

			LL -= (stop - start);
			if (LL > 0) {
				cout << " ";
				text[linie][inceput++] = ' ';
				LL--;
			}
			else {
				cout << endl << " ";
				linie++;
				inceput = 0;
				text[linie][inceput++] = ' ';
				flag = true;
			}
		}
		else {
			if (!flag) {
				cout << endl;
				linie++;
				inceput = 0;
			}
			flag = false;
			LL = L;
			cout << cuv;

			AdaugaCuv(text, cuv, linie, start, stop, inceput);

			LL -= (stop - start);
			if (LL > 0) {
				cout << " ";
				text[linie][inceput++] = ' ';
				LL--;
			}
		}
		start = stop + 1;
	} while (sir[stop] != 0);

	cout << e << e;

	PrintMatrice(text, linie);

	cout << e;

	AlocareMatriceSpatii(spatii, text, linie);
	UI coloana = ReturnColoana(text, linie);
	PrintMatriceSpatii(spatii, linie, coloana);

	cout << e;


	UI Lrau = 0;
	UI index = 0;
	int pozitii[lim3] = { 0 };

	//int vizit[100][100] = { 0 };

	//for (size_t iter = 0; iter <= linie; iter++) {
	//	for (size_t jiter = 0; jiter < coloana; jiter++) {

	//	}
	//}

	// populare pozitii

	for (size_t iter = 0; iter < linie; iter++) {
		for (size_t jiter = 0; jiter < coloana; jiter++) {
			if (spatii[iter][jiter] == 1) {
				pozitii[index++] = jiter;
			}
		}
		pozitii[index++] = 0;
	}

	for (size_t iter = 0; iter < index; iter++) {
		cout << pozitii[iter] << s;
	}
	cout << e << e;


	UI rand = 0;
	for (size_t iter = 0; iter < index; iter++) {
		if (pozitii[iter] != 0) {
			coord[iter].x = rand;
			coord[iter].y = pozitii[iter];
		}
		else {
			rand++;
		}
	}

	// 4 7 9 0 1 2 5 0 2 3 5 0 4 6 7
	// 1 2 3 4 5 6 7 8 9 ..
	UI max = linie;
	UI lin = 0;
	for (size_t iter = 0; iter < index; iter++) {
		if (pozitii[iter] == 0) {
			lin++;
		}
		else {
			if (spatii[lin][pozitii[iter]] != 2) {
				LUNG++;
				PrintXY(lin, pozitii[iter]);
				spatii[lin][pozitii[iter]] = 2;
				Adancime(spatii, lin, pozitii[iter], max);
				cout << e;
			}
		}
		LUNG = 0;
	}

	for (size_t iter = 0; iter <= coloana; iter++) {
		if (spatii[linie][iter] != 2 && spatii[linie][iter] != 0) {
			spatii[linie][iter] = 2;
			PrintXY(linie, iter);
		}
	}

	cout << e << e;

	PrintMatriceSpatii(spatii, linie, coloana);

	//cout << e << MAX;


	// LA FINAL

	if (FLAG) {
		cout << "DA " << MAX << e;
	}
	else {
		cout << "NU" << e;
	}

	//if (spatii[iter + 1][jiter] == 1 ||
	//	spatii[iter + 1][jiter - 1] == 1 ||
	//	spatii[iter][jiter + 1] == 1)
	//{

	//}

	/*start = 0;

	UI inceput = 0;

	CreareCuvant(sir, cuv, start, stop);
	AdaugaCuv(text, cuv, linie, start, stop, inceput);
	text[linie][inceput++] = ' ';
	start = stop + 1;

	linie++;
	inceput = 0;

	CreareCuvant(sir, cuv, start, stop);
	AdaugaCuv(text, cuv, linie, start, stop, inceput);
	text[linie][inceput++] = ' ';
	start = stop + 1;



	cout << text[0] << e;
	cout << text[1] << e;*/

	return 0;
}


void AdaugaCuv(char text[lim2][lim2], char cuv[lim3], UI linie, UI start, UI stop, UI &inceput) {
	UI lungime = stop - start;
	for (size_t iter = 0; iter < lungime; iter++) {
		text[linie][inceput++] = cuv[iter];
	}
}

// un text extrem de simplu si foarte util ca exemplu

void CreareCuvant(char sir[lim5], char cuv[lim3], UI start, UI &stop) {
	int iter = 0, jiter = start;
	while (sir[jiter] != ' ' && sir[jiter] != 0) {
		cuv[iter++] = sir[jiter++];
	}
	cuv[iter] = 0;
	stop = jiter;
}


void PrintMatriceX(char text[][lim2], UI linie) {
	for (size_t iter = 0; iter <= linie; iter++) {
		for (size_t jiter = 0; text[iter][jiter] != 0; jiter++) {
			if (text[iter][jiter] == s) {
				cout << 'X';
			}
			else {
				cout << text[iter][jiter];
			}
		}
		cout << e;
	}
}

/*

PROBLEMA DE LA EXAMEN NU MI SE PARE FOARTE GREU DE REZOLVAT IN TIMPUL ACORDAT
*/