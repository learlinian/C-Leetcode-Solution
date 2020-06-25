#include <vector>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int ans = 0, current_sum=0, A_len = A.size(), left_i=0, right_i=0, right0, left0;
        while (right_i < A_len){
            // init the number for 0s in both left and right sides for current window, min 1
            right0 = 1;
            left0 = 1;

            if (A[right_i] == 1) current_sum++; // add current_sum by 1 if 1 has been detected

            if (S == current_sum){
                // check how many 0s in the right hand side of current window
                while (right0 + right_i < A_len && A[right0 + right_i] == 0) right0++;
                while (left0 + left_i <= right_i && A[left0 + left_i - 1] == 0) left0++;
                ans += right0 * left0;  // available answers = left 0s * right 0s
                left_i += left0;
                if (current_sum > 0) current_sum -= 1;
            }
            // move left pointer rightwards if current sum surpass S value
            while (S < current_sum) current_sum -= A[left_i++];
            right_i++;  // always move right index 1 bit forward
        }
        return ans;
    }
};