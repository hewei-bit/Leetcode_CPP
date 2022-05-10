/**
 * @File Name: BM83 字符串变形.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-09
 *
 */

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    string trans(string s, int n)
    {
        if (n == 0)
            return s;
        string res;

        for (int i = 0; i < n; i++)
        {
            // 大小写转换
            if (s[i] <= 'Z' && s[i] >= 'A')
                res += s[i] - 'A' + 'a';
            else if (s[i] >= 'a' && s[i] <= 'z')
                res += s[i] - 'a' + 'A';
            else
                res += s[i];
        }
        // 翻转整个字符串
        reverse(res.begin(), res.end());
        for (int i = 0; i < n; i++)
        {
            int j = i;

            while (j < n && res[j] != ' ')
                j++;
            reverse(res.begin() + i, res.begin() + j);
            i = j;
        }
        return res;
    }
};