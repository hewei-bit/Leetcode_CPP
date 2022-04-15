/**
 * @File Name: 48. 最长不含重复字符的子字符串.cpp
 * @Brief :
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
    int lengthOfLongestSubstring(string s)
    {
        int len = s.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return 1;
        vector<int> dp(len + 1, 0);
        dp[0] = 1;
        int max = 0;
        for (int i = 1; i < len; i++)
        {
            int j = i - 1;
            while (j >= 0 && s[i] != s[j])
                j--;
            if (dp[i - 1] < i - j) //第j个字符不在dp[i-1]的区间之内
                dp[i] = dp[i - 1] + 1;
            else //第j个字符在dp[i-1]的区间之内
                dp[i] = i - j;
            if (dp[i] > max)
                max = dp[i];
        }
        return max;
    }
};