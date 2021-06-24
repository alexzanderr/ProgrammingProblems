#include <iostream>
#include <string>
#include <cstring>



using namespace std;
// Acccceessttta eesttte uuun exxeeemmppllluu


#define en endl

char* sterge(const char* sir) {

	char* nou = new char[1000];
	strcpy(nou, sir);
	for (size_t iter = 0; iter < strlen(nou) - 1; iter++) {
		while (nou[iter] == nou[iter + 1]) {
			strcpy(nou + iter, nou + iter + 1);
		}
	}
	return nou;
} // Complexitate O(n^2)

char* modifica(char* sir) {
	strncpy(sir, sterge(sir), strlen(sterge(sir)));
	return sir;
}

int main() {

	char exemplu[1000]; 
	cin.getline(exemplu, 1000);
		
	//punctul a

	cout << sterge(exemplu) << en;

	//punctul b
	char* finall = modifica(exemplu);

	cout << finall << en;

	//punctul b alta rezolvare secventiala

	//int k, i = 1, n;
	//char s[101], q;
	//strcpy(s, "Acccceessttta eesttte uuun exxeeemmppllluu");
	//k = 1;
	//q = s[0];
	//n = strlen(s);
	//while (i < n) {
	//	if (s[i] != q) {
	//		q = s[i];
	//		s[k++] = q;
	//	}

	//	i++;
	//}
	//cout << s;

	// Acesta este un exempluuuun exxeeemmppllluu





	// Acesta este un exemplu
	//

	return 0;
}


