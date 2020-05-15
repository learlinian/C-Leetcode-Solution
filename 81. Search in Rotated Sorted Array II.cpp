#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        /* read the checked array */
        // for (auto x : nums) cout<<x<<" ";
        // cout<<endl;

        int len = nums.size(), mid = len/2;
        if (len==0) return false;   // return false if the array is empty
        vector<int> new_nums;       // new array to store subarray

        if (nums[mid] == target) return true;   // return directly if middle value is target
        else if (nums.size() == 1) return nums[mid] == target;  // return if it only has 1 value
        // if target is smaller
        else if (nums[mid] > target){
            if (mid < len-1 && (nums[mid+1] <= nums[mid] || nums[mid+1] >= nums[len-1])){
                new_nums = {nums.begin()+mid+1, nums.end()};
                if (search(new_nums, target)) return true;
            }
            new_nums = {nums.begin(), nums.begin()+mid};
        }
        // if target if larger
        else {
            if (mid > 0 && (nums[mid-1] >= nums[mid] || nums[0] >= nums[mid-1])){
                new_nums = {nums.begin(), nums.begin()+mid};
                if (search(new_nums, target)) return true;
            }
            new_nums = {nums.begin() + mid + 1, nums.end()};
        }
        // check the new sub array
        return search(new_nums, target);
    }
};