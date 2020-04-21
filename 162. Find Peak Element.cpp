#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <cmath>

using namespace std;

class Solution {
public:
    int last_i = 0;
    int findPeakElement(vector<int>& nums) {
        int nums_len = nums.size(), i = nums_len/2;
        if (nums_len == 1) return last_i;
        vector<int>::const_iterator start, end;

        if ((i > 0 && i < nums_len-1 && nums[i-1] < nums[i] && nums[i] > nums[i+1]) || (i==0 && nums[i] > nums[i+1]) || (i==nums_len-1 && nums[i] > nums[i-1])) return last_i+i;
        else{
            if (i < nums_len-1 && nums[i+1] > nums[i]){
                start = nums.begin()+i+1;
                end = nums.end();
                last_i += i+1;
            }
            else {
                start = nums.begin();
                end = nums.begin()+i;
            }
            vector<int> new_nums (start, end);

            return findPeakElement(new_nums);
        }
    }
};