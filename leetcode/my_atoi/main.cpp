#include <iostream>
#include "Solution.hpp"

using namespace std;
    
void Testcase(string testcase, Solution s) {
    cout << "[\"" << testcase << "\" -> " << s.myAtoi(testcase) << "]\n";
}


int main() {
    
    string testcase_1 = "42";
    string testcase_2 = "   -42";
    string testcase_3 = "4193 with words";
    string testcase_4 = "words and 987";
    string testcase_5 = "-91283472332";
    string testcase_6 = "-0";
    string testcase_7 = "0";
    string testcase_8 = "123x123";
    string testcase_9 = "asidhvgasdv huas -0";
    string testcase_10 = "-10 asidhvgasdv huas -0";
    string testcase_11 = "-91283472332";

    string testcases[] = {
        testcase_1,
        testcase_2,
        testcase_3,
        testcase_4,
        testcase_5,
        testcase_6,
        testcase_7,
        testcase_8,
        testcase_9,
        testcase_10,
        testcase_11,
        "           1",
        "        2",
        "       9",
        "0",
        "-22",
        "       -92         a3",
        "-61a    2",
        "+1",
        "+2",
        "+5",
        "+4",
        "    +123123",
        "      +123asda123",
        "       asdas+123123",
        "           1234+123",
        "               ",
        "      ",
        "     123    sad",
        "asd 1        123",
        "+-2",
        "+-4",
        "+-8",
        "+-9",
        "+-112123",
        "+123+1234",
        "+-22323",
        "   +0 123",
        "   +12 3333",
        "   +0        123",
        "-asdasd123",
        "+asdasd123",
        "+-as12354",
        "+-1245asd",
        "2147483648",
        "-2147483648",
        "-2147483649"
    };

    Solution s;

    for (int i = 0; i < sizeof(testcases) / sizeof(testcases[0]); ++i) {
        Testcase(testcases[i], s);
    }
    
    // cout << s.myAtoi(testcase_1) << "\n";
    // cout << s.myAtoi(testcase_2) << "\n";
    // cout << s.myAtoi(testcase_3) << "\n";
    // cout << s.myAtoi(testcase_4) << "\n";
    // cout << s.myAtoi(testcase_5) << "\n";
    // cout << s.myAtoi(testcase_6) << "\n";
    // cout << s.myAtoi(testcase_7) << "\n";
    // cout << s.myAtoi(testcase_8) << "\n";
    // cout << s.myAtoi(testcase_9) << "\n";
    // cout << s.myAtoi(testcase_10) << "\n";
    // cout << s.myAtoi(testcase_11) << "\n";
    

    return 0;
}