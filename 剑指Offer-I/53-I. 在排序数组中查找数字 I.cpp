/**
 * @File Name: 53-I. 在排序数组中查找数字 I.cpp
 * @Brief : 二分查找
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

class Solution
{
public:
    //利用两次二分法分别确定target的左右边界（左右边界为target值序列的左/右一位，因此最终结果是right-left-1）
    int search(vector<int> &nums, int target)
    {

        if (nums.size() == 0)
        {
            return 0;
        }
        //
        int left = 0;
        int right = nums.size() - 1;

        //第一次二分：找right边界

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            //这里是“小于等于”，目的是为了确定右边界，
            // 就是说当mid等于target时，因为不确定后面还有没有target，
            // 所以同样需要左边收缩范围
            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }

        if (right >= 0 && nums[right] != target)
        {
            return 0;
        }

        int right_edge = left;

        // 重置
        left = 0;
        right = nums.size() - 1;
        //第二次二分：找left边界

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            //这里是“大于等于”，目的是确定左边界，
            //  因为就算当mid等于target的时候，因为不确定左边还有没有target，
            // 所以同样需要收缩右边界
            if (nums[mid] >= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        int left_edge = right;

        return right_edge - left_edge - 1;
    }
};