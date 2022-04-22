/**
 * @File Name: 45. �������ų���С����.cpp
 * @Brief : ���� �ַ��� ̰��
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

// ����һ���Ǹ��������飬
// ����������������ƴ�������ų�һ������
// ��ӡ��ƴ�ӳ���������������С��һ����

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