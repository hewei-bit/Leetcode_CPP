/**
 * @File Name: BM52 ������ֻ����һ�ε���������.cpp
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
     *
     *
     * @param array int����vector
     * @return int����vector
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