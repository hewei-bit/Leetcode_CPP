/**
 * @File Name: 1091二进制矩阵中的最短路径.cpp
 * @Brief : BFS
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-14
 *
 */

// 给你一个 n x n 的二进制矩阵 grid 中，返回矩阵中最短 畅通路径 的长度。如果不存在这样的路径，返回 -1 。
// 二进制矩阵中的 畅通路径 是一条从 左上角 单元格（即，(0, 0)）到 右下角 单元格（即，(n - 1, n - 1)）的路径，该路径同时满足下述要求：
// 路径途经的所有单元格都的值都是 0 。
// 路径中所有相邻的单元格应当在 8 个方向之一 上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。
// 畅通路径的长度 是该路径途经的单元格总数。

#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return -1;
        int n = grid.size();
        int ans = 1;
        const int dire[8][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        queue<pair<int, int>> q;
        q.emplace(0, 0);   //从0开始
        grid[0][0] = 1;    // 标记为1代表走过
        while (!q.empty()) // bfs
        {
            for (int i = q.size(); i > 0; i--)
            {
                auto [x, y] = q.front();
                q.pop();
                if (x == n - 1 && y == n - 1)
                    return ans;
                //遍历八个方向的
                for (int i = 0; i < 8; i++)
                {
                    int nx = x + dire[i][0];
                    int ny = y + dire[i][1];
                    //判断是否越界
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    //判断是否能走
                    if (grid[nx][ny] == 0)
                    {
                        q.emplace(nx, ny);
                        grid[nx][ny] = 1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};