#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num<=0)
            return false;
        while(num%2 == 0)
            num /= 2;
        while(num%3 == 0)
            num /= 3;
        while(num%5 == 0)
            num /= 5;
        return num == 1;
    }
};


int main()
{
    Solution s;
    int result = s.isUgly(14);
    cout<<result;
    return 0;
}

