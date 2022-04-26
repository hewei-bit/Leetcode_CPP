/**
 * @File Name: 001. ÕûÊý³ý·¨.cpp
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
    int divide(int a, int b)
    {
        if (a == INT_MIN && b == -1)
            return INT_MAX;
        int sign = (a > 0) ^ (b > 0) ? -1 : 1;

        if (a > 0)
            a = -a;
        if (b > 0)
            b = -b;

        unsigned int res = 0;
        while (a <= b)
        {
            a -= b;
            res++;
        }

        return sign == 1 ? res : -res;
    }
};