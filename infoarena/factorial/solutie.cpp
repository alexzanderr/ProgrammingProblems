#include <iostream>
#include <fstream>

using namespace std;

typedef long long int lli;

ifstream fin("fact.in");
ofstream fout("fact.out");

int NumberOfZeros(int number) {
    int denominator = 5;
    int numberOfZeros = 0;
    while (denominator <= number) {
        numberOfZeros += number / denominator;
        denominator *= 5;
    }
    return numberOfZeros;
}

int main() {

    int P; // reprezinta numarul de zerouri
    fin >> P;

    if (P == 0) {
        fout << 1;
    } else {
        int left = 1;
        int right = 2000000000;
        while (left <= right) {
            int mid = (left + right) >> 1;
            int zeros = NumberOfZeros(mid);
            if (P == zeros) {
                mid -= mid % 5;
                fout << mid;
                //cout << mid;
                return 0;
            } else if (P < zeros) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        fout << -1;
    }

    fin.close();
    fout.close();

    return 0;
}