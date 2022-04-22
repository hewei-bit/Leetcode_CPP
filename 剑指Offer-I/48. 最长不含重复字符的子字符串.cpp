/**
 * @File Name: 48. 最长不含重复字符的子字符串.cpp
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
#include <unordered_set>
#include <algorithm>

using namespace std;

// 请从字符串中找出一个最长的不包含重复字符的子字符串，
// 计算该最长子字符串的长度。
#define DP 0
#define HASH 1
class Solution
{
public:
#if DP
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

#elif HASH
    int lengthOfLongestSubstring(string s)
    {
        /* 哈希集合，记录每个字符是否出现过 */
        unordered_set<char> window;

        /* 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动 */
        int rk = -1, result = 0;
        /* 枚举左指针的位置，初始值隐性地表示为 -1 */
        for (int i = 0; i < s.size(); i++)
        {
            if (i != 0)
            {
                window.erase(s[i - 1]);
            }

            while (rk + 1 < s.size() && window.find(s[rk + 1]) == window.end())
            {
                window.insert(s[rk + 1]);
                rk++;
            }
            /* 第 i 到 rk 个字符是一个极长的无重复字符子串 */
            result = max(result, rk - i + 1);
        }
        return result;
    }
#endif
};