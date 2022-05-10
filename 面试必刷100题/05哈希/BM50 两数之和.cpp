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