/**
 * @File Name: 47. 礼物的最大价值.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-15
 *
 */

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;
        int col = grid[0].size();
        int row = grid.size();
        int dp[row][col];
        dp[0][0] = grid[0][0];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0 || j == 0)
                {
                    if (i == 0)
                        dp[i][j] = grid[i][j] + dp[i][j - 1];
                    if (j == 0)
                        dp[i][j] = grid[i][j] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = grid[i][j] + max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[row - 1][col - 1];
    }
};