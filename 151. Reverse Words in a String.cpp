#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <cmath>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int string_len = s.length(), end_i = string_len-1, i;
        bool end_found = false;
        string result;

        for (i = string_len-1; i >= 0 ; i--){
            if (!end_found && s[i] != ' '){
                end_i = i;
                end_found = true;
            }
            else if (end_found && s[i] == ' '){
                end_found = false;
                result += (result.length() == 0)? s.substr(i+1, end_i-i) : ' ' + s.substr(i+1, end_i-i);
            }
        }

        if (end_found) result += (result.length() == 0)? s.substr(i+1, end_i-i) : ' ' + s.substr(i+1, end_i-i);
        return result;
    }
};