/**
 * @File Name: 1091�����ƾ����е����·��.cpp
 * @Brief : BFS
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-14
 *
 */

// ����һ�� n x n �Ķ����ƾ��� grid �У����ؾ�������� ��ͨ·�� �ĳ��ȡ����������������·�������� -1 ��
// �����ƾ����е� ��ͨ·�� ��һ���� ���Ͻ� ��Ԫ�񣨼���(0, 0)���� ���½� ��Ԫ�񣨼���(n - 1, n - 1)����·������·��ͬʱ��������Ҫ��
// ·��;�������е�Ԫ�񶼵�ֵ���� 0 ��
// ·�����������ڵĵ�Ԫ��Ӧ���� 8 ������֮һ ����ͨ��������������Ԫ֮��˴˲�ͬ�ҹ���һ���߻���һ���ǣ���
// ��ͨ·���ĳ��� �Ǹ�·��;���ĵ�Ԫ��������

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
        q.emplace(0, 0);   //��0��ʼ
        grid[0][0] = 1;    // ���Ϊ1�����߹�
        while (!q.empty()) // bfs
        {
            for (int i = q.size(); i > 0; i--)
            {
                auto [x, y] = q.front();
                q.pop();
                if (x == n - 1 && y == n - 1)
                    return ans;
                //�����˸������
                for (int i = 0; i < 8; i++)
                {
                    int nx = x + dire[i][0];
                    int ny = y + dire[i][1];
                    //�ж��Ƿ�Խ��
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    //�ж��Ƿ�����
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