/**
 * @File Name: 56 - I. 数组中数字出现的次数.cpp
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
    vector<int> singleNumbers(vector<int> &nums)
    {
        int x = 0, y = 0, n = 0, m = 1;
        for (int num : nums)
            n ^= num; // 1. 遍历异或
        while ((n & m) == 0)
            m <<= 1;         // 2. 循环左移，计算 m
        for (int num : nums) // 3. 遍历 nums 分组
        {
            if (num & m)
                x ^= num;
            else
                y ^= num;
        }
        return vector<int>{x, y}; // 5. 返回出现一次的数字
    }
};