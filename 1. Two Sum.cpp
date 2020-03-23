#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> temp(nums);
        vector<int> solution;
        sort(temp.begin(), temp.end());
        int i = 0, j = temp.size()-1;
        while (i < j){
            if (temp[i] + temp[j] < target)
                i++;
            else if (temp[i] + temp[j] > target)
                j--;
            else {
                auto it = find(nums.begin(), nums.end(), temp[i]);
                solution.push_back(it-nums.begin());
//                if (temp[i] == temp[j])
//                    nums.erase(it);
                it = find(it+1, nums.end(), temp[j]);
                solution.push_back(it);
//                if (temp[i] == temp[j])
//                    solution.push_back(it-nums.begin()+1);
//                else
//                    solution.push_back(it-nums.begin());
                break;
            }
        }
        return solution;
    }
};


int main()
{
    Solution s;
    vector<int> results, inputs{-1, -2, -3, -4, -5};

    results = s.twoSum(inputs, -8);
    for (int x: results)
        cout << x << " ";
    return 0;
}

