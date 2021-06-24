#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long reversed = 0;
        int copy_x = x;
        while (x != 0) {
            reversed = reversed * 10 + x % 10;
            if (reversed <= INT32_MIN || reversed >= INT32_MAX) {
                return false;
            }
            x /= 10;
        }
        return copy_x == reversed;
    }
};