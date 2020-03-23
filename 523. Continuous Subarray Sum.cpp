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
    bool checkSubarraySum(vector<int>& nums, int k) {
        int nums_len = nums.size(), i, j;
        if(k==0){
            for(i=1; i<nums_len; i++){
                if(nums[i] == 0 && nums[i-1] == 0)
                    return true;
            }
            return false;
        }

        vector<int> values(nums_len, -1);
        for(i=0; i<nums_len; i++){
            values[i] = nums[i] % k;
            for(j=0; j<i; j++){
                values[j] = (values[j]+nums[i]) % k;
                if (values[j] == 0)
                    return true;
            }
        }
        return false;
    }
};



int main()
{
    Solution s;

    vector<int> nums{23, 2, 6, 4, 7};
    int k = 6;
    cout<<s.checkSubarraySum(nums, k);
    return 0;
}

