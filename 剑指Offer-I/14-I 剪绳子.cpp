/**
 * @File Name: 14-I ¼ôÉþ×Ó.cpp
 * @Brief : Ì°ÐÄËã·¨
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
        int a = n / 3, b = n % 3;
        if (b == 0)
            return (int)pow(3, a);
        if (b == 1)
            return (int)pow(3, a - 1) * 4;
        return (int)pow(3, a) * 2;
    }
};