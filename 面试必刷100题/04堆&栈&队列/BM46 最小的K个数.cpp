/**
 * @File Name: BM46 最小的K个数.cpp
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

// priority_queue()，默认按照从小到大排列。所以top()返回的是最大值而不是最小值！

// 使用greater<>后，数据从大到小排列，top()返回的就是最小值而不是最大值！

// 如果使用了第三个参数，那第二个参数不能省，用作保存数据的容器！！！！

class Solution
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> res;

        if (k == 0 || input.size() == 0)
        {
            return res;
        }

        priority_queue<int> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push(input[i]);
        }

        for (int i = k; i < input.size(); i++)
        {
            if (pq.top() > input[i])
            {
                pq.pop();
                pq.push(input[i]);
            }
        }

        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};