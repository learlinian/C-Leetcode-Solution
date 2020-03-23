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
    double findMaxAverage(vector<int>& nums, int k) {
        int max_sum, i=1, sum;
        if(nums.size() < k)
            return float(accumulate(nums.begin(), nums.end(), 0))/nums.size();
        sum = accumulate(nums.begin(), nums.begin()+k, 0);
        max_sum = sum;

        while(i<nums.size()-k+1){
            sum += (nums[i+k-1] - nums[i-1]);
            max_sum = max(max_sum, sum);
            i ++;
        }

        return double(max_sum)/k;
    }
};



int main()
{
    Solution s;
    vector<int> str{1,3, 4, -1};

    cout << s.findMaxAverage(str, 1);
    return 0;
}

