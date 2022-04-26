/**
 * @File Name: 67. 把字符串转换成整数.cpp
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
    int strToInt(string str)
    {
        long int ans = 0;
        bool sign = false;
        int l = str.length();
        int i = 0;

        while (str[i] == ' ' && i < l)
        {
            i++;
        }

        if (str[i] == '-' || str[i] == '+')
        {
            str[i] == '-' ? sign = true : sign = false;
            i++;
        }

        if ((str[i] < '0') || (str[i] > '9'))
        {
            return 0;
        }

        while (i < l)
        {
            if (str[i] < '0' || str[i] > '9')
            {
                break;
            }
            ans *= 10;
            ans += str[i] - '0';
            i++;
            if (ans > INT_MAX)
            {
                return sign ? INT_MIN : INT_MAX;
            }
        }
        return sign ? -ans : ans;
    }
};