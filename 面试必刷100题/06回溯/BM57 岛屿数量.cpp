/**
 * @File Name: BM57 岛屿数量.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-30
 *
 */

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    /**
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>>
     * @return int整型
     */
    int solve(vector<vector<char>> &grid)
    {
        int n = grid.size();

        if (n == 0)
        {
            return 0;
        }

        int m = grid[0].size();

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    DFS(grid, i, j);
                }
            }
        }

        return count;
    }

    void DFS(vector<vector<char>> &grid, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();

        grid[i][j] = '0';

        if (i - 1 >= 0 && grid[i - 1][j] == '1')
            DFS(grid, i - 1, j);
        if (i + 1 < n && grid[i + 1][j] == '1')
            DFS(grid, i + 1, j);
        if (j - 1 >= 0 && grid[i][j - 1] == '1')
            DFS(grid, i, j - 1);
        if (j + 1 < m && grid[i][j + 1] == '1')
            DFS(grid, i, j + 1);
    }
};