/**
 * @File Name: 63. ��Ʊ���������.cpp
 * @Brief : ��̬�滮
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
            // ǰi���������=max(ǰ(i?1)���������,��i�ռ۸�?ǰi����ͼ۸�)
            dp[i] = max(dp[i - 1], prices[i] - minPrice);
        }
        return dp[n - 1];
    }
};