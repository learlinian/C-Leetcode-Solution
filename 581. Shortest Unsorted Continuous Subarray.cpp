#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <string>
#include <cmath>

using namespace std;

class Solution{
public:
    int findUnsortedSubarray(vector<int>& nums){
        int start=0, end=0, i;
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());
        for(i=0; i<nums.size(); i++){
            if(temp[i] != nums[i]) {
                start = i;
                break;
            }
        }

        for(i=nums.size()-1; i>=0; i--){
            if(temp[i] != nums[i]) {
                end = i;
                break;
            }
        }

        if (start*end == 0)
            return 0;
        return end-start+1;
    }
};



int main()
{
    Solution s;
//    vector<int> str{2, 6, 4, 8, 10, 9, 15};
//    vector<int> str{1, 3, 2, 2, 2};
//    vector<int> str{1,2,3,4};
    vector<int> str{1, 2, 4, 5, 3};

//    vector<int> str{2,3,3,2,4};
    cout << s.findUnsortedSubarray(str);
    return 0;
}

