/**
 * @File Name: BM45 滑动窗口的最大值.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-17
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
    vector<int> maxInWindows(const vector<int> &nums, int size)
    {
        int n = nums.size();
        if (n < size || size <= 0)
            return {};

        int low = 1 - size, high = 0;

        deque<int> dp;
        vector<int> res;

        while (high < n)
        {
            if (low >= 1 && nums[low - 1] == dp[0])
                dp.pop_front();

            while (!dp.empty() && dp[0] < nums[high])
                dp.pop_front();
            while (!dp.empty() && dp[dp.size() - 1] < nums[high])
                dp.pop_back();

            dp.push_back(nums[high]);

            if (low >= 0)
                res.push_back(dp[0]);

            low++;
            high++;
        }
        return res;
    }
};