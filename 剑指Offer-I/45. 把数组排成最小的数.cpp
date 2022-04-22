/**
 * @File Name: 45. 把数组排成最小的数.cpp
 * @Brief : 排序 字符串 贪心
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
#include <set>
#include <algorithm>

using namespace std;

// 输入一个非负整数数组，
// 把数组里所有数字拼接起来排成一个数，
// 打印能拼接出的所有数字中最小的一个。

class Solution
{
public:
    string minNumber(vector<int> &nums)
    {
        vector<string> strs;
        for (int i = 0; i < nums.size(); i++)
        {
            strs.push_back(to_string(nums[i]));
        }
        QuickSort(strs, 0, nums.size() - 1);
        string res;
        for (string s : strs)
            res.append(s);
        return res;
    }

private:
    void QuickSort(vector<string> &strs, int l, int r)
    {
        if (l >= r)
            return;
        int i = l, j = r;
        while (i < j)
        {
            while (i < j && strs[j] + strs[l] >= strs[l] + strs[j])
                j--;
            while (i < j && strs[i] + strs[l] <= strs[l] + strs[i])
                i++;
            swap(strs[i], strs[j]);
        }
        swap(strs[i], strs[l]);
        QuickSort(strs, l, i - 1);
        QuickSort(strs, i + 1, r);
    }
};