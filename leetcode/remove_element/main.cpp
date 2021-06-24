#include <iostream>
#include <fstream>
#include "Solution.hpp"

using namespace std;

void Testcase(int case_number, vector<int> array, int value) {
    Solution s;
    cout << "Testcase #" << case_number << ": ([ ";
    for (size_t i = 0; i < array.size(); ++i) {
        cout << array[i] << " ";
    }
    cout << "], " << value << ") -> " << s.removeElement(array, value) << "\n";
}

int main() {
    vector<pair<vector<int>, int>> testcases;
    testcases.push_back(pair<vector<int>, int> {{3,2,2,3}, 3});
    testcases.push_back(pair<vector<int>, int> {{0,1,2,2,3,0,4,2}, 2});

    // testcases.push_back(vector<int> {3,2,2,3});
    // testcases.push_back(vector<int> {3,2,2,3});
    // testcases.push_back(vector<int> {3,2,2,3});

    for (size_t i = 0; i < testcases.size(); ++i) {
        Testcase(i + 1, testcases[i].first, testcases[i].second);
    }
    return 0;
}