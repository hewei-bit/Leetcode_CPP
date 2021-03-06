/**
 * @File Name: 62. 圆圈中最后剩下的数字.cpp
 * @Brief : 递归、数学
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
    int lastRemaining(int n, int m)
    {
        vector<int> dp(n + 1, 0);
        int x = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + m) % i;
            // x = (x + m) % i;
        }
        return dp[n];
    }
};