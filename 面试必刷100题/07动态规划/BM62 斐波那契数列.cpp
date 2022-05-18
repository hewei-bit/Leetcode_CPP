/**
 * @File Name: BM62 ì³²¨ÄÇÆõÊýÁÐ.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-18
 *
 */
#include <iostream>
#include <cstdio>
#include <cmath>

#include <queue>
#include <stack>
#include <unordered_map>
#include <set>

#include <algorithm>

using namespace std;

class Solution
{
public:
    int Fibonacci(int n)
    {
        if (n <= 1)
            return 1;
        int res = 0;
        int a = 0;
        int b = 1;

        for (int i = 2; i < n; i++)
        {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};