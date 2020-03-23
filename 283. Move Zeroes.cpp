#include <iostream>
#include <vector>
#include <algorithm>
//#include <typeinfo>
//#include <string>
//#include <cmath>
//#include <numeric>
//#include <stack>
//#include <map>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int nums_len = nums.size();
        int start = 0, end = 0;
        if (nums_len > 1) {
            while (end < nums_len && nums[start] != 0){
                start++;
                end++;
            }

            while (end < nums_len) {
                while (end < nums_len && nums[end] == 0)
                    end++;
                if (end < nums_len) {
                    swap(nums[start], nums[end]);
                    while (nums[start] != 0)
                        start++;
                }
            }

             for(int i=0; i<5; i++)
                 cout<<nums[i]<<" ";
        }
    }
};


int main()
{
    Solution s;
    vector<int> inputs{0,1,0,3,12};

    s.moveZeroes(inputs);
//    for (int x: results)
//        cout << x << " ";
    return 0;
}

