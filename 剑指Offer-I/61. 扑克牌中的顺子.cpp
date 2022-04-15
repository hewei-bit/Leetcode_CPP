/**
 * @File Name: 61. 扑克牌中的顺子.cpp
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

class Solution
{
public:
    bool isStraight(vector<int> &nums)
    {
        int joker = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == 0)
                joker += 1;
            else if (nums[i] == nums[i + 1])
                return false;
        }
        return nums[4] - nums[joker] < 5;
    }
};