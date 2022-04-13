/**
 * @File Name: 04 二维数组中的查找.cpp
 * @Brief : 二分查找
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-13
 *
 */
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        int i = matrix.size() - 1;
        int j = 0;
        while (i >= 0 && j < matrix[0].size())
        {
            if (matrix[i][j] > target)
                i--;
            else if (matrix[i][j] < target)
                j++;
            else
                return true;
        }
        return false;
    }
};