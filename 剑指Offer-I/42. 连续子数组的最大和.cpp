/**
 * @File Name: 42. 连续子数组的最大和.cpp
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

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int n = nums.size();
        int max = 0;

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        max = dp[0];

        for (int i = 1; i < n; i++)
        {
            if (dp[i - 1] > 0)
            {
                dp[i] = dp[i - 1] + nums[i];
            }
            else
            {
                dp[i] = nums[i];
            }
            max = (max > dp[i]) ? max : dp[i];
        }
        return max;
    }
};