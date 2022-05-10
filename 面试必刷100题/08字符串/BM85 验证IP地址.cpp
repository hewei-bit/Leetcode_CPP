/**
 * @File Name: BM85 验证IP地址.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-09
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

using namespace std;

class Solution
{
public:
    vector<string> split(string s, string spliter)
    {
        vector<string> res;
        int i;
        while ((i = s.find(spliter)) && i != s.npos)
        {
            //
            res.push_back(s.substr(0, i));
            s = s.substr(i + 1);
        }
        res.push_back(s);
        return res;
    }

    bool isIPv4(string IP)
    {
        vector<string> s = split(IP, ".");
        // IPv4 必定是4组
        if (s.size() != 4)
        {
            return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            // 不可缺省
            if (s[i].size() == 0)
                return false;
            // 比较位数，并且不能有0前缀
            if (s[i].size() < 0 || s[i].size() > 3 || (s[i][0] == '0' && s[i].size() != 1))
            {
                return false;
            }
            // 遍历字符串,必须为数字
            for (int j = 0; j < s[i].size(); j++)
            {
                if (!isdigit(s[i][j]))
                    return false;
            }
            // 转化为数字比较，大小
            int num = stoi(s[i]);
            if (num < 0 || num > 255)
                return false;
        }
        return true;
    }

    bool isIPv6(string IP)
    {
        vector<string> s = split(IP, ":");
        // IPv6 必定为8组
        if (s.size() != 8)
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            // 不可缺省
            if (s[i].size() == 0 || s[i].size() > 4)
                return false;
            // 合法性检测
            for (int j = 0; j < s[i].size(); j++)
            {
                if (!(isdigit(s[i][j]) ||
                      (s[i][j] >= 'a' && s[i][j] <= 'f') ||
                      (s[i][j] >= 'A' && s[i][j] <= 'F')))
                    return false;
            }
        }
        return true;
    }

    string solve(string IP)
    {
        if (IP.size() == 0)
            return "Neither";
        if (isIPv4(IP))
            return "IPv4";
        if (isIPv6(IP))
            return "IPv6";

        return "Neither";
    }
};