#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int a;
	int b;

	ifstream input("adunare.in");

	input >> a;
	input >> b;

	input.close();

	ofstream output("adunare.out");

	output << a + b;
	
	return 0;	
}
