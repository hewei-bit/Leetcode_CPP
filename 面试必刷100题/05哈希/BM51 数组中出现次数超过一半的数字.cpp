/**
 * @File Name: BM51 数组中出现次数超过一半的数字.cpp
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
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < numbers.size(); i++)
        {
            hash[numbers[i]]++;
            if (hash[numbers[i]] > numbers.size() / 2)
                return numbers[i];
        }
        return 0;
    }
};