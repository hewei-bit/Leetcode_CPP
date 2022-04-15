/**
 * @File Name: 29. ˳ʱ���ӡ����.cpp
 * @Brief : ���顢����
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-14
 *
 */
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return {};
        vector<int> res;

        //��߽磬�ұ߽磬�ϱ߽磬�±߽�
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
        while (true)
        {
            for (int i = left; i <= right; i++)
                res.push_back(matrix[top][i]);
            if (++top > bottom)
                break;

            for (int i = top; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            if (--right < left)
                break;

            for (int i = right; i >= left; i--)
                res.push_back(matrix[bottom][i]);
            if (--bottom < top)
                break;

            for (int i = bottom; i >= top; i--)
                res.push_back(matrix[i][left]);
            if (++left > right)
                break;
        }
        return res;
    }
};