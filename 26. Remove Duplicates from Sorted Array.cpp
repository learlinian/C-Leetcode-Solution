#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=nums.size()-1; i>0; i--){
            if (nums[i] == nums[i-1])
                nums.erase(nums.begin()+i);
        }
        return nums.size();
    }
};


int main()
{
    Solution s;
    vector<int> inputs{1, 2, 2};

    int result = s.removeDuplicates(inputs);
    cout << result;
    return 0;
}

