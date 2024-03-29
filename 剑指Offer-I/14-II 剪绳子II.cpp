/**
 * @File Name: 14-II ������II.cpp
 * @Brief : ̰���㷨
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
    int cuttingRope(int n)
    {
        if (n <= 3)
            return n - 1;
        int b = n % 3, p = 1000000007;
        long rem = 1, x = 3;
        for (int a = n / 3 - 1; a > 0; a /= 2)
        {
            if (a % 2 == 1)
                rem = (rem * x) % p;
            x = (x * x) % p;
        }
        if (b == 0)
            return (int)(rem * 3 % p);
        if (b == 1)
            return (int)(rem * 4 % p);
        return (int)(rem * 6 % p);
    }
};