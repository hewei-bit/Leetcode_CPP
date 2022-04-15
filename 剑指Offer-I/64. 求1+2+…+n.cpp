/**
 * @File Name: 64. Çó1+2+¡­+n.cpp
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
    int sumNums(int n)
    {
        return n > 0 ? n + sumNums(n - 1) : 0;
    }
};