/**
 * @File Name: BM86 大数加法.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2023-04-22
 *
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
#include <string>

using namespace std;
class Solution
{
public:
    string solve(string s, string t)
    {
        if (s.empty())
            return t;
        if (t.empty())
            return s;
        // 让s较长 t较短
        if (s.length() < t.length())
            swap(s, t);
        // 进位标志
        int carry = 0;
        // 从后往前加
        for (int i = s.length() - 1; i >= 0; i--)
        {
            // 转数字加上进位
            int temp = s[i] - '0' + carry;
            // 获得较短字符串的下标
            int j = i - s.length() + t.length();
            // 如果较短字符串还有
            if (j >= 0)
                temp += t[j] - '0';
            carry = temp / 10;
            temp = temp % 10;
            // 修改结果
            s[i] = temp + '0';
        }
        // 最后进位
        if (carry == 1)
            s = '1' + s;
        return s;
    }
};