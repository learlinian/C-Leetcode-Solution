#include <iostream>
#include <vector>
#include <algorithm>
//#include <typeinfo>
#include <string>
//#include <cmath>
//#include <numeric>
//#include <stack>
//#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int s_len = s.length(), i=s_len-1;
        while (s[i] == ' ') {
            i--;
            s_len--;
        }
        while(i>=0){
            i--;
            if (s[i] == ' ')
                return s_len-i-1;
        }
        return s_len;
    }
};


int main()
{
    Solution s;
//    vector<int> inputs{0,1,0,3,12};
    string a = "Hello World";
//    string a = "a ";
    cout<<s.lengthOfLastWord(a);

    return 0;
}

