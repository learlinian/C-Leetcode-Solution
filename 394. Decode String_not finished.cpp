#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <string>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i=0, j, s_len = s.length(), current_size;
        string result, current_s, temp, num;
        vector<int> count;
        vector<string> store;

        while(i<s.length()){
            if(s[i] != '[' && s[i] != ']'){
                current_s = "";
                if(s[i]-'0' >=0 && s[i]-'0' <9) {
                    num = "";
                    while(s[i]-'0' >=0 && s[i]-'0' <9){
                        num += s[i];
                        i++;
                    }
                    count.push_back(stoi(num));
                    i += 1;
                }
                else
                    count.push_back(1);
                while(s[i] != ']') {
                    current_s += s[i];
                    if(i+1 == s.length() || s[i+1] == ']' || (s[i+1]-'0' >=0 && s[i+1]-'0' <9)) {
                        store.push_back(current_s);
                        break;
                    }
                    i++;
                }
            }
            if(s[i] == ']' || i+1 == s.length()){
                current_size = store.size();
                cout<<"current_size: "<<current_size;
                temp = store[current_size - 1];
                for (j = 0; j < count[current_size - 1]-1; j++)
                    store[current_size - 1] += temp;
                if(current_size > 1) {
                    for (j = current_size - 2; j >= 0; j--) {
                        store[j] += store[j + 1];
                    }
                }
                else {
                    result += store[0];
                    for (string x: store)
                        cout << x << " ";
                    for (int y: count)
                        cout << y << " ";
                }
                cout<<result<<endl;
                store.pop_back();
                count.pop_back();
            }
            if(store.size()==1){
                result += store[0];
            }
            i++;

        }
        return result;
    }
};



int main()
{
    Solution s;
//    string str = "12[a]1[bc]";
//    string str = "3[a2[c]]";
//    string str = "2[abc]3[cd]ef";
//    string str = "abc";
    string str="3[a]2[b4[F]c]";
    cout<<s.decodeString(str);
    return 0;
}

