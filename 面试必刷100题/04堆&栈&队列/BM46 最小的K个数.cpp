/**
 * @File Name: BM46 ��С��K����.cpp
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

// priority_queue()��Ĭ�ϰ��մ�С�������С�����top()���ص������ֵ��������Сֵ��

// ʹ��greater<>�����ݴӴ�С���У�top()���صľ�����Сֵ���������ֵ��

// ���ʹ���˵������������ǵڶ�����������ʡ�������������ݵ�������������

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