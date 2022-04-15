/**
 * @File Name: 46. 把数字翻译成字符串.cpp
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
    int translateNum(int num)
    {
        string str = to_string(num);
        int len = str.size();
        if (len < 2)
            return 1;
        vector<int> dp(len + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= len; i++)
        {
            if (str[i - 2] == '1' || (str[i - 2] == '2' && str[i - 1] <= '5'))
                dp[i] = dp[i - 2] + dp[i - 1];
            else
                dp[i] = dp[i - 1];
        }
        return dp[len];
    }
};