#include <iostream>
#include <fstream>

using namespace std;

pair<int*, int> GetArray(ifstream& fin) {
    int *array = new int[100000]{0};
    int x;
    int index = 0;
    while (fin >> x) {
        array[index++] = x;
    }

    pair<int*, int> array_and_length;
    array_and_length.first = array;
    array_and_length.second = index;

    return array_and_length;
}

void PrintArray(int* array, int length) {
    for (int i = 0; i < length; ++i) {
        cout << array[i] << " "; 
    }
    cout << endl;
}

void Solution1(ifstream& fin) {
    pair<int*, int> AL = GetArray(fin);
    int *array = AL.first;
    int length = AL.second;

    int begin = -1, end = -1;
    int max_sum = 0;
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            int sum = 0;
            for (int k = i; k <= j; ++k) {
                sum += array[k];
            }
            if (sum > max_sum) {
                max_sum = sum;
                begin = i;
                end = j;
            }
        }
    }

    cout << max_sum << " at i: " << begin << " and j: " << end << "\n";
    fin.close();
}

void Solution2(ifstream& fin) {
    pair<int*, int> AL = GetArray(fin);
    int* array = AL.first;
    int length = AL.second;

    int *sum = new int[length];
    sum[0] = array[0];
    // sum[0] = 0;
    for (int i = 1; i < length ; ++i) {
        sum[i] = array[i] + sum[i - 1];
    }
    
    PrintArray(array, length);

    for (int i = 0; i < length; ++i) {
        cout << sum[i] << " ";
    }
    cout << "\n";

    int max_sum = 0;
    int begin = -1, end = -1;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j <= i; ++j) {
            int diff = sum[i] - sum[j];
            // max_sum = (diff > max_sum) ? diff : max_sum;
            if (diff > max_sum) {
                max_sum = diff;
                begin = j;
                end = i;
            }
        }
    }
    begin++;
    cout << max_sum << " at: [" << begin << " " << end << "]\n";
    fin.close();
}

int main() {
    ifstream fin1("input1.in");
    Solution1(fin1);

    ifstream fin2("input2.in");
    Solution2(fin2);

    return 0;
}