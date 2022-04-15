/**
 * @File Name: 31. ջ��ѹ�롢��������.cpp
 * @Brief : ջ
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-14
 *
 */

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int i = 0;
        for (int num : pushed)
        {
            s.push(num);
            while (!s.empty() && s.top() == popped[i])
            {
                s.pop();
                i++;
            }
        }
        return s.empty();
    }
};