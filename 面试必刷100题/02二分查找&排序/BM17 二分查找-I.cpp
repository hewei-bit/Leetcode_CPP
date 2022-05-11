/**
 * @File Name: BM17 ¶þ·Ö²éÕÒ-I.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-08
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
    /**
     * ????????????????????????????????????
     *
     *
     * @param nums int??vector
     * @param target int??
     * @return int??
     */
    int search(vector<int> &nums, int target)
    {
        if (nums.size() <= 0)
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] == target)
            {
                return mid;
            }
        }
        return -1;
    }
};