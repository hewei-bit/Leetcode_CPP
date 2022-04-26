/**
 * @File Name: 60. n个骰子的点数.cpp
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
#include <stdio.h>
#include <string.h>

using namespace std;

class Solution
{
public:
    vector<double> dicesProbability(int n)
    {
        // vector<vector<double>> dp;
        int dp[15][70];
        memset(dp, 0.0, sizeof(dp));

        for (int i = 1; i < 7; i++)
        {
            dp[1][i] = 1;
        }

        for (int i = 2; i < n + 1; i++)
        {
            for (int j = i; j < 6 * i + 1; j++)
            {
                for (int k = 1; k < 7; k++)
                {

                    dp[i][j] += dp[i - 1][j - k];

                    if (j - k <= 0)
                    {
                        break;
                    }
                }
            }
        }

        int all = pow(6, n);
        vector<double> res(5 * n + 1, 0.0);
        int index = 0;

        for (int i = n; i < 6 * n + 1; i++)
        {
            res[index++] = (dp[n][i] * 1.0 / all);
        }

        return res;
    }
};