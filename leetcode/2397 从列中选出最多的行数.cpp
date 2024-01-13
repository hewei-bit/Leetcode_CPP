/**
 * @File Name: 2397 从列中选出最多的行数.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2024-01-05
 *
 */

#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    int maximumRows(vector<vector<int>> &matrix, int numSelect)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> masks(m, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                masks[i] |= (matrix[i][j] << j);
            }
        }
        backtracking(masks, numSelect, n, 0, 0);
        return maxRows;
    }

private:
    int maxRows = 0;
    /**
     * 对当前idx列有选与不选两种选择
     * @param masks: 每一行的数字掩码
     * @param numSelect: 当前还可以选择的列数
     * @param n: 总列数，也是列索引上界
     * @param idx：当前处理的列索引
     * @param s: 选择的列集合掩码
     */
    void backtracking(vector<int> &masks, int numSelect, int n, int idx, int s)
    {
        if (numSelect == 0)
        {
            int coverRows = 0;
            for (auto &mask : masks)
            {
                coverRows += 1 - min(1, mask & ~s);
            }
            maxRows = max(maxRows, coverRows);
            return;
        }
        if (idx == n)
            return;
        backtracking(masks, numSelect, n, idx + 1, s);
        s |= (1 << idx);
        backtracking(masks, numSelect - 1, n, idx + 1, s);
        return;
    }
};