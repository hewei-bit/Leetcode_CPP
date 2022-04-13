/**
 * @File Name: 15 ��������1�ĸ���.cpp
 * @Brief : λ����
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
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        while (n != 0)
        {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};