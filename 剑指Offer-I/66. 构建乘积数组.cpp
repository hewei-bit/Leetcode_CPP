/**
 * @File Name: 66. 构建乘积数组.cpp
 * @Brief : 数组、前缀和
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
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> constructArr(vector<int> &a)
    {
        int len = a.size();
        if (len == 0)
            return {};
        vector<int> b(len, 1);

        int tmp = 1;
        for (int i = 1; i < len; i++)
        {
            b[i] = b[i - 1] * a[i - 1];
        }

        for (int i = len - 2; i >= 0; i--)
        {
            tmp *= a[i + 1];
            b[i] *= tmp;
        }

        return b;
    }
};