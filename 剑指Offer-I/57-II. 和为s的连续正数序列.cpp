/**
 * @File Name: 57 - II. 和为s的连续正数序列.cpp
 * @Brief : 双指针
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
    vector<vector<int>> findContinuousSequence(int target)
    {
        int i = 1, j = 2, s = 3;
        vector<vector<int>> res;
        while (i < j)
        {
            if (s == target)
            {
                vector<int> tmp;
                for (int k = i; k <= j; k++)
                {
                    tmp.push_back(k);
                }
                res.push_back(tmp);
            }
            if (s >= target)
            {
                s -= i;
                i++;
            }
            else
            {
                j++;
                s += j;
            }
        }
        return res;
    }
};