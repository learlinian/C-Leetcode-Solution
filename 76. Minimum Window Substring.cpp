#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <cmath>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hist(128, 0);
        for(char c: t) hist[c]++;

        int left = 0, right = 0, min_left = 0, min_len = numeric_limits<int>::max();
        int remaining = t.length();

        while (right < s.length()){
            if (--hist[s[right++]] >= 0)  remaining--;

            while (remaining == 0) {
                if (right - left < min_len){
                    min_left = left;
                    min_len = right - left;
                }
                if (++hist[s[left++]] > 0)   remaining++;
            }
        }
        return min_len < numeric_limits<int>::max() ? s.substr(min_left, min_len) : "";
    }
};

//int main(){
//    string S{"ADOBECODEBANC"}, T{"ABC"};
//    Solution s;
//    string result = s.minWindow(S, T);
//    cout<<result;
//    return 0;
//}