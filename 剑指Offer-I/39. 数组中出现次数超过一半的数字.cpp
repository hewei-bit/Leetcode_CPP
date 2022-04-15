/**
 * @File Name: 39. 数组中出现次数超过一半的数字.cpp
 * @Brief : 数学
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-14
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
    int majorityElement(vector<int> &nums)
    {
        // 众数
        int x = 0, votes = 0, count = 0;
        for (int num : nums)
        {
            // 假设此时的数字是众数
            if (votes == 0)
                x = num;
            votes += num == x ? 1 : -1;
        }
        // 进行验证
        for (int num : nums)
        {
            if (num == x)
                count++;
        }
        return count > nums.size() / 2 ? x : 0;
    }
};