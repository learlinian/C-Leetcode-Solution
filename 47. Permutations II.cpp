#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <string>
#include <cmath>
#include <numeric>

using namespace std;

class Solution{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result{{nums}};
        vector<int> final_position;
        int nums_len = nums.size(), i, j, min_swap, swap_i, temp;
        final_position = nums;
        reverse(final_position.begin(), final_position.end());
        while(nums != final_position) {
//            for(int x=0; x<nums.size(); x++)
//                cout<<nums[x]<<" ";
//            cout << endl;
            for (i = nums_len - 2; i >= 0; i--) {
                if (nums[i] < nums[i + 1]) {
                    min_swap = pow(2, 16);
                    swap_i = -1;
                    for (j = i+1; j < nums_len; j++) {
                        if (nums[j] > nums[i] && nums[j] < min_swap) {
                            min_swap = nums[j];
                            swap_i = j;
                        }
                    }
                    if (swap_i != -1) {
                        temp = nums[swap_i];
                        nums[swap_i] = nums[i];
                        nums[i] = temp;
                        sort(nums.begin() + i + 1, nums.end());
                        result.push_back(nums);
                        break;
                    }
                }
            }
        }
        return result;
    }
};



int main()
{
    Solution s;
    vector<int> str{1,1,2,2};
    vector<vector<int>> results = s.permuteUnique(str);
    for(int i=0; i<results.size(); i++){
        for (int j=0; j<results[0].size(); j++)
            cout<<results[i][j]<<" ";
        cout << endl;
    }
    return 0;
}

