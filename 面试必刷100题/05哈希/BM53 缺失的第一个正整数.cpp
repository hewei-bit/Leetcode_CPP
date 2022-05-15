/**
 * @File Name: BM53 缺失的第一个正整数.cpp
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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * @param nums int整型vector
     * @return int整型
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