/**
 * @File Name: BM20 数组中的逆序对.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-11
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
private:
    int count;

public:
    int InversePairs(vector<int> data)
    {
        count = 0;
        mergeSort(data, 0, data.size() - 1);
        return count;
    }
    void mergeSort(vector<int> &nums, int left, int right)
    {
        if (nums.empty() || left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
    void merge(vector<int> &nums, int left, int mid, int right)
    {
        int *tmp = new int[right - left + 1];
        int i = left, j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
                tmp[k++] = nums[i++];
            else
            {
                tmp[k++] = nums[j++];
                count += (mid - i + 1);
            }
        }
        while (i <= mid)
        {
            tmp[k++] = nums[i++];
        }
        while (j <= right)
        {
            tmp[k++] = nums[j++];
        }

        for (i = 0; i < k; i++)
        {
            nums[left + i] = tmp[i];
        }

        delete[] tmp;
    }
};