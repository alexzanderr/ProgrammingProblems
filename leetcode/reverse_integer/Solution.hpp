#include <iostream>
#include <cmath>
#include <climits>

using namespace std;
    
class Solution {
public:
    int reverse(int x) {
        int new_number = 0;
        int power = 1;
        while (x != 0) {
            int digit = x % 10;
            // 7 is the last digit in INT32_MAX
            // and
            // -7 is the last digit in INT32_MIN
            if ((new_number > INT32_MAX / 10 || (new_number == INT32_MAX / 10 && digit > 7))
                ||
                (new_number < INT32_MIN / 10 || (new_number == INT32_MIN / 10 && digit < -8))) 
            {
                return 0;
            }
            new_number = new_number * 10 + digit;
            x /= 10;
        }
        return new_number;
    }
};