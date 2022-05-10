/**
 * @File Name: BM85 ��֤IP��ַ.cpp
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
        // IPv4 �ض���4��
        if (s.size() != 4)
        {
            return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            // ����ȱʡ
            if (s[i].size() == 0)
                return false;
            // �Ƚ�λ�������Ҳ�����0ǰ׺
            if (s[i].size() < 0 || s[i].size() > 3 || (s[i][0] == '0' && s[i].size() != 1))
            {
                return false;
            }
            // �����ַ���,����Ϊ����
            for (int j = 0; j < s[i].size(); j++)
            {
                if (!isdigit(s[i][j]))
                    return false;
            }
            // ת��Ϊ���ֱȽϣ���С
            int num = stoi(s[i]);
            if (num < 0 || num > 255)
                return false;
        }
        return true;
    }

    bool isIPv6(string IP)
    {
        vector<string> s = split(IP, ":");
        // IPv6 �ض�Ϊ8��
        if (s.size() != 8)
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            // ����ȱʡ
            if (s[i].size() == 0 || s[i].size() > 4)
                return false;
            // �Ϸ��Լ��
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