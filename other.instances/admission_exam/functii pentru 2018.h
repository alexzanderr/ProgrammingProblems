#pragma once

#include <iostream>

using namespace std;

typedef unsigned int UI;

#define e '\n'
#define s ' '

void PrintXY(int x, int y) {
	cout << "[" << x << "," << y << "] ";
}

UI MAX = 0;
UI LUNG = 0;
bool FLAG = false;

void Adancime(int spatii[][100], UI lin, UI pozitie, UI max) {
	if (lin == max) {
		if (LUNG > MAX) {
			MAX = LUNG;
		}
		return;
	}
	if (spatii[lin + 1][pozitie] == 1) {
		PrintXY(lin + 1, pozitie);
		LUNG++;
		FLAG = true;
		if (spatii[lin + 1][pozitie] != 2) {
			spatii[lin + 1][pozitie] = 2;
			Adancime(spatii, lin + 1, pozitie, max);
		}
	}
	else if (spatii[lin + 1][pozitie - 1] == 1) {
		PrintXY(lin + 1, pozitie - 1);
		LUNG++;
		FLAG = true;
		if (spatii[lin + 1][pozitie - 1] != 2) {
			spatii[lin + 1][pozitie - 1] = 2;
			Adancime(spatii, lin + 1, pozitie - 1, max);
		}

	}
	else if (spatii[lin + 1][pozitie + 1] == 1) {
		PrintXY(lin + 1, pozitie + 1);
		LUNG++;
		FLAG = true;
		if (spatii[lin + 1][pozitie + 1] != 2) {
			spatii[lin + 1][pozitie + 1] = 2;
			Adancime(spatii, lin + 1, pozitie + 1, max);
		}
	}
	else {
		return;
	}
}