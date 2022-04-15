/**
 * @File Name: 48. ������ظ��ַ������ַ���.cpp
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
            if (dp[i - 1] < i - j) //��j���ַ�����dp[i-1]������֮��
                dp[i] = dp[i - 1] + 1;
            else //��j���ַ���dp[i-1]������֮��
                dp[i] = i - j;
            if (dp[i] > max)
                max = dp[i];
        }
        return max;
    }
};