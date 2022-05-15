/**
 * @File Name: BM50 两数之和.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-10
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
/*
通俗的讲end（）并没有指向一个元素，
或者可以说是指向一个空的位置，
即end（）函数返回的不是指向最后一个元素的迭代器，
而是指向最后一个元素后面的位置的迭代器。
*/
class Solution
{
public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> res;
        unordered_map<int, int> hash;

        for (int i = 0; i < numbers.size(); i++)
        {
            int temp = target - numbers[i];
            if (hash.find(temp) == hash.end())
            {
                hash[numbers[i]] = i;
            }
            else
            {
                res.push_back(hash[temp] + 1);
                res.push_back(i + 1);
                break;
            }
        }
        return res;
    }
};