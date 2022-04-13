/**
 * @File Name: 13 机器人的运动范围.cpp
 * @Brief : DFS
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-13
 *
 */
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int movingCount(int m, int n, int k)
    {
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        int res = dfs(visited, m, n, k, 0, 0);
        return res;
    }

private:
    int dfs(vector<vector<bool>> &visited, int m, int n, int k, int i, int j)
    {
        // 终止条件
        if (i >= m || i < 0 || j < 0 || j >= n || visited[i][j] || BitSum(i) + BitSum(j) > k)
            return 0;
        visited[i][j] = true;
        return 1 + dfs(visited, m, n, k, i + 1, j) + dfs(visited, m, n, k, i, j + 1);
    }

    int BitSum(int x)
    {
        int s = 0;
        while (x != 0)
        {
            s += x % 10;
            x = x / 10;
        }
        return s;
    }
};