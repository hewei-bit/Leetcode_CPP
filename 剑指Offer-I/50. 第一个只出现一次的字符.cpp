/**
 * @File Name: 50. 第一个只出现一次的字符.cpp
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
    char firstUniqChar(string s)
    {
        unordered_map<char, bool> dic;
        for (char c : s)
        {
            dic[c] = dic.find(c) == dic.end();
        }

        for (char c : s)
        {
            if (dic[c])
                return c;
        }

        return ' ';
    }
};