/**
 * @File Name: 56 合并区.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2024-01-14
 *
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++)
        {
            int left = intervals[i][0];
            int right = intervals[i][1];
            // 检查最后一个的右边有没有比新的左边小，小就push
            // 否则就更新最后一个的右边
            // 注意：如果res为空，直接push
            if (!res.size() || res.back()[1] < left)
            {
                res.push_back({left, right});
            }
            else
            {
                res.back()[1] = max(res.back()[1], right);
            }
        }
        return res;
    }
};
