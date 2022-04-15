/**
 * @File Name: 05 Ìæ»»¿Õ¸ñ.cpp
 * @Brief : ×Ö·û´®
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-13
 *
 */
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string replaceSpace(string s)
    {
        string res;
        for (auto &c : s)
        {
            if (c == ' ')
            {
                res.push_back('%');
                res.push_back('2');
                res.push_back('0');
            }
            else
            {
                res.push_back(c);
            }
        }
        return res;
    }
};