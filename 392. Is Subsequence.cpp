#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <string>
#include <cmath>
#include <numeric>
#include <stack>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_len = s.length(), t_len = t.length(), i, j=0;
        for(i=0; i<s_len; i++){
            while(j < t_len && t[j] != s[i])
                j++;
            j++;
            if (j>t_len)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;

    string str = "abc", t = "ahbgdc";

    cout<<s.isSubsequence(str, t);
    return 0;
}

