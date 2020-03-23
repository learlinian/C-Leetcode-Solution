#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n, 1);
        int i=0, j=0, k=0, l=1;

        while (l<n){
            v[l] = min(v[i]*2, min(v[j]*3, v[k]*5));
            while (v[i]*2 <= v[l])
                i++;
            while (v[j]*3 <= v[l])
                j++;
            while (v[k]*5 <= v[l])
                k++;
            l++;
        }
        return v.back();
    }
};



int main()
{
    Solution s;
    cout << s.nthUglyNumber(37);
    return 0;
}

