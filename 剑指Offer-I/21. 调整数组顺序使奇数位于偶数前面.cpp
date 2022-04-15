/**
 * @File Name: 21 调整数组顺序使奇数位于偶数前面.cpp
 * @Brief : 双指针
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

using namespace std;

class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            while (i < j && (nums[i] % 2) == 1)
                i++;
            while (i < j && (nums[j] % 2) == 0)
                j--;
            std::swap(nums[i], nums[j]);
        }
        return nums;
    }
};