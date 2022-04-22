/**
 * @File Name: 57. ��Ϊs����������.cpp
 * @Brief : ˫ָ�롢���ֲ���
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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        int s = 0;
        while (i < j)
        {
            if (nums[i] + nums[j] < target)
                i++;
            else if (nums[i] + nums[j] > target)
                j--;
            else
                return {nums[i], nums[j]};
        }
        return {};
    }
};