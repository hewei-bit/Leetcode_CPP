/**
 * @File Name: 16 数值的整数次方.cpp
 * @Brief : 数学
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-13
 *
 */
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0)
            return 0;
        long b = n;
        double res = 1.0;
        if (b < 0)
        {
            x = 1 / x;
            b = -b;
        }
        while (b > 0)
        {
            if ((b & 1) == 1)
                res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
    }
};