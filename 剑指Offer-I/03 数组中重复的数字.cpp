/**
 * @File Name: 03 数组中重复的数字.cpp
 * @Brief : 哈希表
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-13
 *
 */

// 找出数组中重复的数字。
// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
// 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
// 请找出数组中任意一个重复的数字。

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        unordered_map<int, bool> res;
        for (int num : nums)
        {
            if (res[num])
                return num;
            res[num] = true;
        }
        return -1;
    }
};