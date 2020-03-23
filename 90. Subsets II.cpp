#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <string>
#include <cmath>
#include <numeric>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> stack;
        vector<vector<int>> result{{}};
        sort(nums.begin(), nums.end());
        int nums_len = nums.size(), i, j, k, pop_count = 0;
        recursive(nums, stack, result);
        return result;
    }

private:
    void recursive(vector<int>& nums_new, vector<int>& stack, vector<vector<int>>& result){
        vector<int> sub_vec(nums_new.begin()+1, nums_new.end());
        for(int i=0; i<nums_new.size(); i++){
            cout<<"stack: ";
            for (int temp: stack)
                cout << temp << " ";
            cout << endl<<"sub_vec: ";
            for (int temp: sub_vec)
                cout << temp << " ";
            cout << endl<<endl;

            stack.push_back(nums_new[i]);
            if(find(result.begin(), result.end(), stack)==result.end())
                result.push_back(stack);
            recursive(sub_vec, stack, result);
            stack.pop_back();
        }
    }
};

int main()
{
    Solution s;

    vector<int> arr{1, 2, 2};
    vector<vector<int>> results;
    results = s.subsetsWithDup(arr);
    for(vector<int> x: results) {
        for (int y: x)
            cout << y << " ";
        cout<<endl;
    }
    return 0;
}

