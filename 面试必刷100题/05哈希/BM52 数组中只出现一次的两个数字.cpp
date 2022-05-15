/**
 * @File Name: BM52 数组中只出现一次的两个数字.cpp
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
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int> &array)
    {
        unordered_map<int, int> hash;
        vector<int> res;
        for (int i = 0; i < array.size(); i++)
        {
            hash[array[i]]++;
        }

        for (int i = 0; i < array.size(); i++)
        {
            if (hash[array[i]] == 1)
                res.push_back(array[i]);
        }

        if (res[0] < res[1])
            return res;
        else
            return {res[1], res[0]};
    }
};