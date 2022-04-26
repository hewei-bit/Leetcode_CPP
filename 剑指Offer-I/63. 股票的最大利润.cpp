/**
 * @File Name: 63. 股票的最大利润.cpp
 * @Brief : 动态规划
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
    int maxProfit(vector<int> &prices)
    {

        if (prices.empty())
            return 0;

        int minPrice = INT_MAX;
        int n = prices.size();

        vector<int> dp(n, 0);
        dp[0] = 0;

        for (int i = 1; i < n; i++)
        {
            minPrice = min(minPrice, prices[i - 1]);
            // 前i日最大利润=max(前(i?1)日最大利润,第i日价格?前i日最低价格)
            dp[i] = max(dp[i - 1], prices[i] - minPrice);
        }
        return dp[n - 1];
    }
};