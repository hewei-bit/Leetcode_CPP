/**
 * @File Name: 49. 丑数.cpp
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
#include <set>
#include <algorithm>

using namespace std;

// 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。
// 求按从小到大的顺序的第 n 个丑数。

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int a = 0, b = 0, c = 0;
        int dp[n];
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
            dp[i] = min(min(n2, n3), n5);
            if (dp[i] == n2)
                a++;
            if (dp[i] == n3)
                b++;
            if (dp[i] == n5)
                c++;
        }
        return dp[n - 1];
    }
};