#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <cmath>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> adding;
        int i, num = gas.size(), max_i = 0, total = 0, check_gas = 0;
        bool new_i = true;

        for (i = 0; i < num; i++)
            adding.push_back(gas[i] - cost[i]);

        for (i = 0; i < num; i++){
            total += adding[i];

            if (total < 0){
                total = 0;
                new_i = true;
            }

            else if (new_i){
                max_i = i;
                new_i = false;
            }
        }

        vector<int> new_adding (adding.begin()+max_i, adding.end());
        new_adding.insert(new_adding.end(), adding.begin(), adding.begin()+max_i);

        for (i = 0; i < num; i++){
            check_gas += new_adding[i];
            if (check_gas < 0) return -1;
        }

        return max_i;
    }
};