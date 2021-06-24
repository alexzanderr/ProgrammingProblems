#include <iostream>
#include <fstream>

using namespace std;

void SolveProblemMethod1(ifstream& fin) {
    int number;
    fin >> number;
    int single_number = number;
    while (fin >> number) {
        single_number ^= number;
    }
    cout << "the number without pair is: " << single_number << "\n";
}

int main() {
    ifstream fin("input.in");

    SolveProblemMethod1(fin);

    fin.close();
    return 0;
}