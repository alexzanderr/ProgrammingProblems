#include <iostream>
#include "Solution.hpp"

using namespace std;

int main() {
    
    int x = 123;
    int y = -123;
    int z = -120;
    int z2 = -12320300;
    int over = 12880721002330700LL;
    int over2 = 760318872123300700L;
    int test = -2147483412;
    int test1 = 1463847412;

    // cout << -123123 % 10 << "\n";
    // cout << -12 % 10 << "\n";
    // cout << -1 % 10 << "\n";

    Solution s;
    cout << s.reverse(x) << "\n";
    cout << s.reverse(y) << "\n";
    cout << s.reverse(z) << "\n";
    cout << s.reverse(z2) << "\n";
    cout << s.reverse(over) << "\n";
    cout << s.reverse(over2) << "\n";
    cout << s.reverse(test) << "\n";
    cout << s.reverse(test1) << "\n";

    return 0;
}