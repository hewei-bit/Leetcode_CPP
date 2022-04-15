/**
 * @File Name: 43. 1～n 整数中 1 出现的次数.cpp
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
    int countDigitOne(int n)
    {
        long digit = 1;
        int res = 0;
        int high = n / 10, cur = n % 10, low = 0;
        while (high != 0 || cur != 0)
        {
            if (cur == 0)
                res += high * digit;
            else if (cur == 1)
                res += high * digit + low + 1;
            else
                res += high * digit + digit;

            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};