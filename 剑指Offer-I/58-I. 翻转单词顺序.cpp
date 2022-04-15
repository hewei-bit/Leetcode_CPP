/**
 * @File Name: 58-I. ·­×ªµ¥´ÊË³Ðò.cpp
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
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string res;
        int len = s.size();
        if (len == 0)
            return res;

        int right = len - 1;
        int left = right;

        while (right >= 0)
        {
            while (right >= 0 && s[right] == ' ')
                right--;
            if (right < 0)
                break;

            left = right;
            while (left >= 0 && s[left] != ' ')
                left--;

            res += s.substr(left + 1, right - left);
            res += ' ';

            right = left;
        }

        if (!res.empty())
            res.pop_back();
        return res;
    }
};