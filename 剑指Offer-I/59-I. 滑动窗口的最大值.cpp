/**
 * @File Name: 59-I. �������ڵ����ֵ.cpp
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
//�������ڵ����ֵ
//�趨˫�˶��� deque ʵ�ַ��ϸ�ݼ��ĵ������У����׾��ǵ�ǰ�����ڵ����Ԫ��
// 1 - ����������Ԫ��ǡ���ǵ������еĶ�ͷԪ�أ�һ���ջ
// 2 - ������С���¼���Ԫ�صĵ�������Ԫ�س��ӣ���Ԫ�����
// 3 - �γɻ�����ȡ����Ԫ�ؼ����� res
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

            // ˫�˶����б�nums[high]������ȥ
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