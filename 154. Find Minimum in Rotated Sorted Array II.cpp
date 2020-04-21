#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <cmath>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int nums_len = nums.size(), i;
        for (i = 1; i < nums_len; i++){
            if (nums[i] < nums[i-1]) return nums[i];
        }

        return nums[0];
    }
};