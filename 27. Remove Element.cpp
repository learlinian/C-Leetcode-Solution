#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=nums.size()-1; i>=0; i--){
            if (nums[i] == val)
                nums.erase(nums.begin()+i);
        }
        return nums.size();
    }
};


int main()
{
    Solution s;
    vector<int> inputs{3, 2, 2, 3};

    int result = s.removeElement(inputs, 2);
    cout << result;
    return 0;
}

