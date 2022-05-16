/**
 * @File Name: BM54 三数之和.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-15
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
    vector<vector<int>> threeSum(vector<int> &num)
    {
        vector<vector<int>> res;
        int n = num.size();
        if (n < 3)
            return res;

        sort(num.begin(), num.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (i != 0 && num[i] == num[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            int target = -num[i];

            while (left < right)
            {
                if (num[left] + num[right] == target)
                {
                    res.push_back({num[i], num[left], num[right]});
                    while (left + 1 < right && num[left] == num[left + 1])
                        left++;
                    while (right - 1 > left && num[right] == num[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (num[left] + num[right] < target)
                    left++;
                else
                    right--;
            }
        }
        return res;
    }
};