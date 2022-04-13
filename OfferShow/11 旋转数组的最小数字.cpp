/**
 * @File Name: 11 旋转数组的最小数字.cpp
 * @Brief : 二分查找
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-13
 *
 */
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (numbers[mid] > numbers[right])
                left = mid + 1;
            else if (numbers[mid] < numbers[right])
                right = mid;
            else
                right--;
        }
        return numbers[left];
    }
};