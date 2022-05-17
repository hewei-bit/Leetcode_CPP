/**
 * @File Name: BM47 Ñ°ÕÒµÚK´ó.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-17
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
    int findKth(vector<int> a, int n, int K)
    {
        quickSort(a, 0, n - 1);
        return a[n - K];
    }

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