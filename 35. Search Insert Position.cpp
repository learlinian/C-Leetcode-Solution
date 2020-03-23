#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        do{
            int k = (i+j+1)/2;
            if (nums[k] == target)
                return k;
            if (nums[i] == target)
                return i;
            if (nums[j] == target)
                return j;
            if (nums[k] < target)
                i = (i+j+1)/2;
            else
                j = (i+j+1)/2;
        }while (i < j -1);
        if (target<nums[i])
            return i;
        else if (target>nums[j])
            return j+1;
        else
            return j;
    }
};


int main()
{
    Solution s;
    vector<int> inputs{1};

    int result = s.searchInsert(inputs, 0);
    cout << result;
    return 0;
}

