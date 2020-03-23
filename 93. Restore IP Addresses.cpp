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

//class Solution {
//public:
//    vector<string> restoreIpAddresses(string s) {
//        vector<string> results;
//        vector<string> records;
//        string record_comb;
//
//        int s_len = s.length();
//        int i=1, j=1, k=1;
//        for(i=1; i<=3; i++){
//            records = {s.substr(0, i)};
//            if (stoi(records.back())>255 || (records.back()[0] == '0'))
//                continue;
//            for(j=1; j<=3; j++){
//                records.push_back(s.substr(i, j));
//                if (stoi(records.back())>255 || (records.back()[0] == '0')) {
//                    records.pop_back();
//                    break;
//                }
//                for(k=1; k<=3; k++){
//                    records.push_back(s.substr(i+j, k));
//                    if (stoi(records.back())>255 || (records.back()[0] == '0')) {
//                        records.pop_back();
//                        break;
//                    }
//                    if (stoi(s.substr(i+j+k, s_len-i-j-k))<=255 && (s.substr(i+j+k, s_len-i-j-k)[0] != '0')) {
//
//                    }
//                }
//            }
//        }
//        return results;
//    }
//};

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        string record_comb;

        int s_len = s.length();
        int i=1, j=1, k=1;
        while (i<=3){
            if (i+j+k<s_len && s_len-i-j-k <=3 && stoi(s.substr(i+j+k, s_len-i-j-k)) <= 255 && (s[i+j+k] != '0' || s_len-i-k-j==1) && stoi(s.substr(0, i)) <= 255 && (s[0] != '0' || i==1) && stoi(s.substr(i, j)) <= 255 && (s[i] != '0' || j == 1) && stoi(s.substr(i + j, k)) <= 255 && (s[i+j] != '0' || k==1)) {
                record_comb = s.substr(0, i) + "." + s.substr(i, j) + "." + s.substr(i + j, k) + "." + s.substr(i+j+k, s_len-i-j-k);
                results.push_back(record_comb);
            }
            if (k<3)
                k++;
            else if (j<3) {
                j++;
                k=1;
            }
            else {
                i++;
                j=1;
                k=1;
            }
        }
        return results;
    }
};
int main()
{
    Solution s;
//    vector<int> inputs{0,1,0,3,12};
//    string a = "25525511135";
    string a = "0279245587303";
    vector<string> results = s.restoreIpAddresses(a);
    for(const auto & result : results)
        cout<<result<<endl;

    return 0;
}


