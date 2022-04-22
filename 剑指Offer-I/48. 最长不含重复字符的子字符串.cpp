/**
 * @File Name: 48. ������ظ��ַ������ַ���.cpp
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
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

// ����ַ������ҳ�һ����Ĳ������ظ��ַ������ַ�����
// ���������ַ����ĳ��ȡ�
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
            if (dp[i - 1] < i - j) //��j���ַ�����dp[i-1]������֮��
                dp[i] = dp[i - 1] + 1;
            else //��j���ַ���dp[i-1]������֮��
                dp[i] = i - j;

            if (dp[i] > max)
                max = dp[i];
        }
        return max;
    }

#elif HASH
    int lengthOfLongestSubstring(string s)
    {
        /* ��ϣ���ϣ���¼ÿ���ַ��Ƿ���ֹ� */
        unordered_set<char> window;

        /* ��ָ�룬��ʼֵΪ -1���൱���������ַ�������߽����࣬��û�п�ʼ�ƶ� */
        int rk = -1, result = 0;
        /* ö����ָ���λ�ã���ʼֵ���Եر�ʾΪ -1 */
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
            /* �� i �� rk ���ַ���һ�����������ظ��ַ��Ӵ� */
            result = max(result, rk - i + 1);
        }
        return result;
    }
#endif
};