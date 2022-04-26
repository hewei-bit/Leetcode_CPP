/**
 * @File Name: 59-I. 滑动窗口的最大值.cpp
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
//滑动窗口的最大值
//设定双端队列 deque 实现非严格递减的单调队列，队首就是当前滑窗内的最大元素
// 1 - 当出滑窗的元素恰好是单调队列的队头元素，一起出栈
// 2 - 让所有小于新加入元素的单调队列元素出队，新元素入队
// 3 - 形成滑窗后，取队首元素加入结果 res
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n < k || k <= 0)
            return {};

        int low = 1 - k, high = 0;

        deque<int> dp;
        vector<int> res;

        while (high < n)
        {

            if (low >= 1 && nums[low - 1] == dp[0])
                dp.pop_front();

            // 双端队列中比nums[high]都弹出去
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