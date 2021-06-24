#include <iostream>
#include <fstream>

using namespace std;

void PrintInterval(int i, int j) {
    cout << "[" << i << " " << j << "]";
}




void SolveProblem1(ifstream& fin) {
    int n;
    fin >> n;

    int *array = new int[n];
    int length = 0;
    for (int i = 0; i < n; ++i) {
        int number;
        fin >> number;
        array[length++] = number;
    }

    int begin = -1;
    int end = -1;
    int lung_maxima = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 2; j < n; ++j) {
            if (i < j) {
                bool all_lower = true;
                for (int k = i + 1; k < j; ++k) {
                    if (array[k] > array[i] || array[k] > array[j]) {
                        all_lower = false;
                        break;
                    }
                }
                if (all_lower) {
                    int diff = j - i;
                    // lung_maxima = (diff > lung_maxima) ? diff : lung_maxima;
                    if (diff > lung_maxima) {
                        lung_maxima = diff;
                        begin = i;
                        end = j;
                    }
                }
            }
        }
    }
    lung_maxima--;
    PrintInterval(begin, end);
    cout << "\nwith length: " << lung_maxima << "\n";
}

int main() {
    ifstream fin("input.in");
    
    SolveProblem1(fin);

    fin.close();
    return 0;
}