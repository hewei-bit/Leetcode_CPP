/**
 * @File Name: 40. 最小的k个数.cpp
 * @Brief : 排序
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-14
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
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        quickSort(arr, 0, arr.size() - 1);
        vector<int> res;
        res.assign(arr.begin(), arr.begin() + k);
        return res;
    }

private:
    void quickSort(vector<int> &arr, int left, int right)
    {
        if (left > right)
            return;

        int i = left, j = right;
        while (i < j)
        {
            while (i < j && arr[j] >= arr[left])
                j--;
            while (i < j && arr[i] <= arr[left])
                i++;
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[left]);

        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
};