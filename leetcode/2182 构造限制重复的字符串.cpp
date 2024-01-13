/**
 * @File Name: 2182 构造限制重复的字符串.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2024-01-13
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        // 预处理统计每个字符出现的次数
        vector<int> count(26);
        for (auto &ch : s)
        {
            count[ch - 'a']++;
        }
        // 找到出现字符中字典序最大字母的索引
        int maxChar = 25;
        while (count[maxChar] == 0)
        {
            maxChar--;
        }
        // 找到出现字符中字典序第二大字母的索引
        int secondMaxChar = maxChar - 1;
        while (secondMaxChar >= 0 && count[secondMaxChar] == 0)
        {
            secondMaxChar--;
        }
        // 构造字符串
        string ans;
        while (maxChar >= 0)
        {
            int repeat = min(count[maxChar], repeatLimit);
            count[maxChar] -= repeat;
            while (repeat-- > 0)
            {
                ans += (char)('a' + maxChar);
            }
            // 如果没有第二大的就退出
            if (secondMaxChar < 0)
                break;
            if (count[maxChar] == 0)
            {
                maxChar = secondMaxChar;
                secondMaxChar--;
            }
            else
            {
                ans += (char)('a' + secondMaxChar);
                count[secondMaxChar]--;
            }
            while (secondMaxChar >= 0 && count[secondMaxChar] == 0)
                secondMaxChar--;
        }
        return ans;
    }
};
