/**
 * @File Name: 1991找到数组的中间位置.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2024-01-13
 *
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int findMiddleIndex(vector<int> &nums)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int leftsum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (2 * leftsum + nums[i] == total)
            {
                return i;
            }
            leftsum += nums[i];
        }
        return -1;
    }
};