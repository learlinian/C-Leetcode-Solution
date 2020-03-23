#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int col=obstacleGrid[0].size(), row=obstacleGrid.size();
        if (row == 0 || col == 0 || obstacleGrid[0][0] == 1)
            return 0;
        unsigned int arr[row][col];
        int i=0;
        for (;i<col; i++) {
            if (obstacleGrid[0][i] == 0)
                arr[0][i] = 1;
            else {
                arr[0][i] = 0;
                break;
            }
        }
        while (i<col){
            arr[0][i] = 0;
            i++;
        }

        i=1;
        for (;i<row; i++) {
            if (obstacleGrid[i][0] == 0)
                arr[i][0] = 1;
            else {
                arr[i][0] = 0;
                break;
            }
        }
        while (i<row){
            arr[i][0] = 0;
            i++;
        }
//        cout<<"row: " << row << "; col" << col << endl;
        for (int j=1;j<col; j++) {
            for(i=1; i<row; i++) {
                if (obstacleGrid[i][j] == 1)
                    arr[i][j] = 0;
                else {
                    arr[i][j] = arr[i-1][j] + arr[i][j-1];
                }
            }
//            cout<<endl;
        }

//        for(int x=0; x<row; x++){
//           for (int y=0; y<col; y++)
//               cout<<arr[x][y]<<" ";
//            cout<<endl;
//        }
        return arr[row-1][col-1];
    }
};


int main()
{
    Solution s;
    vector<vector<int>> inputs{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    int result = s.uniquePathsWithObstacles(inputs);
    cout << result;
    return 0;
}

