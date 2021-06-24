#include <iostream>

using namespace std;
    
class Solution {
public:

    string deleteFirstWhiteSpaces(string str) {
        if (str[0] == ' ') {
            int index = -1;
            for (size_t i = 1; i < str.size(); ++i) {
                if (str[i] != ' ') {
                    index = i;
                    break;
                }
            }
            if (index != - 1) {
                string new_str = "";   
                for (size_t i = index; i < str.size(); ++i) {
                    new_str += str[i];
                }
                return new_str;
            } else {
                return "";
            }
        } else {
            return str;
        }
    }

    bool isDigit(char character) {
        switch (character) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                return true;
            default:
                return false;
        }
    }

    int myAtoi(string str) {
        if (str == "") {
            return 0;
        }
        str = deleteFirstWhiteSpaces(str);
        if (str == "") {
            return 0;
        }
        string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        
        // if the first character after deletion of the white spaces is a letter
        for (size_t i = 0; i < alpha.size(); ++i) {
            if (str[0] == alpha[i]) {
                return 0;
            }
        }

        // if (str.size() == 1) {
        //     if (isDigit(str[0])) {
        //         return (str[0]  - '0');
        //     }
        // }
        // we delete the white spaces


        int first_digit = -1;
        for (size_t i = 0; i < str.size(); ++i) {
            if (isDigit(str[i])) {
                first_digit = i;
                break;
            }
        }   


        // index == 0 OK
        // index == 1 and str[0] == '+' or str[0] == '-' O
        if (first_digit == 0 || (first_digit == 1 && (str[0] == '+' || str[0] == '-'))) {
            bool negative = false;

            if (str[0] == '-') {
                negative = true;
            }

            string new_number = "";
            new_number += str[first_digit];
            for (size_t i = first_digit + 1; i < str.size(); ++i) {
                if (!isDigit(str[i])) {
                    break;       
                }
                new_number += str[i];
            }
            // cout << "\n" << new_number << "\n\n";

            int number = new_number[0] - '0';
            if (negative) {
                number = -number;
            }
            for (size_t i = 1; i < new_number.size(); ++i) {
                int digit = new_number[i] - '0';
                if (negative) {
                    digit = -digit;
                }

                // if (number > INT32_MAX) {
                //     return INT32_MAX;
                // } else if (number < INT32_MIN) {
                //     return INT32_MIN;
                // }

                if (number > INT32_MAX / 10 || (number == INT32_MAX / 10 && digit > 7)) {
                    // if (negative) {
                    //     return -INT32_MAX;
                    // }
                    return INT32_MAX;
                } else if (number < INT32_MIN / 10 || (number == INT32_MIN / 10 && digit < -8)) {
                    // if (negative) {
                    //     return -INT32_MIN;
                    // } 
                    return INT32_MIN;
                }
                number = number * 10 + digit;
            }                

            return number;
        } 

        // in this case its
        return 0;


        // else NOT OK
        // index == 2 and (str[1] == '+' and str[0] == '-') 
        // or (str[1] == '-' and str[0] == '+') NOK
        // else not ok
        
        

        // int firstDigit = -1;
        // for (size_t i = 0; i < str.size() - 1; ++i) {
        //     if (isDigit(str[i])) {
        //         firstDigit = i;
        //         break;
        //     } else if ((str[i] == '-' && isDigit(str[i + 1])) 
        //                 ||
        //               (str[i]) == '+' && isDigit(str[i + 1])) {
        //         firstDigit = i + 1;
        //         break;
        //     } 
        // }
        // if (firstDigit != -1) {
        //     // cout << "first digit: " << str[firstDigit] << " on pos: " << firstDigit << "\n";

        //     bool neg_sign = false;
        //     bool pos_sign = false;

        //     for (int i = 0; i < str.size(); ++i) {
        //         if (str[i] == '-') {
        //             neg_sign = true;
        //         } else if(str[i] == '+') {
        //             pos_sign = true;
        //         }
        //         if (pos_sign && neg_sign) {
        //             return 0;
        //         }
        //     }

        //     string number_str = "";
        //     bool negative = false;
        //     if (str[0] == '-') {
        //         negative = true;
        //     }

        //     for (size_t i = firstDigit; i < str.size(); ++i) {
        //         if (!isDigit(str[i])) {
        //             break;
        //         } 
        //         number_str += str[i];
        //     }


            

        //     // cout << number_str << "\n";

        //     // cout << "The number is: " << number_str << "\n";

        //     // putting the first digit
        //     int number = number_str[0] - '0';

        //     // cout << number << "\n";
        //     // if (negative) {
        //     //     number = -number;
        //     // }

        //     for (size_t i = 1; i < number_str.size(); ++i) {
        //         int digit = number_str[i] - '0';
        //         if (number > INT32_MAX / 10 || (number == INT32_MAX / 10 && digit > 7)) {
        //             if (negative) {
        //                 return INT32_MIN;
        //             } else {
        //                 return INT32_MAX;
        //             }
        //         } else if (number < INT32_MIN / 10 || (number == INT32_MIN / 10 && digit < -8)) {
        //             if (negative) {
        //                 return -INT32_MIN;
        //             } else {
        //                 return -INT32_MAX;
        //             }
        //         }
        //         number = number * 10 + digit;
        //     }
        //     if (negative) {
        //         return -number;
        //     }
        //     return number;
        // }
    }
};