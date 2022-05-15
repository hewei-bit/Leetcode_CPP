/**
 * @File Name: BM53 ȱʧ�ĵ�һ��������.cpp
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
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * @param nums int����vector
     * @return int����
     */
    int minNumberDisappeared(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> hash;

        for (int i = 0; i < n; i++)
            hash[nums[i]]++;

        int res = 1;
        while (hash.find(res) != hash.end())
            res++;

        return res;
    }
};