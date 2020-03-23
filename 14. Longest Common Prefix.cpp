#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
//#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int str_items = strs.size(), i=0;
        if (str_items==0)
            return "";
        int str_len = strs[0].length();
        string check_str;
        bool check = true;

        while (i<str_len){
            check_str = strs[0].substr(0, i+1);
            char check_c = strs[0][i];
            for (int j=0; j<str_items; j++){
                if (strs[j][i]!=check_c){
                    check_str = check_str.substr(0, check_str.length()-1);
                    check = false;
                    break;
                }
            }
            if (!check)
                break;
            i++;
        }

        return check_str;
    }
};


int main()
{
    Solution s;
    vector<string> inputs{"aflower","flow","cflight"};

    string result = s.longestCommonPrefix(inputs);
    cout << result;
    return 0;
}

