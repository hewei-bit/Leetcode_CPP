/**
 * @File Name: BM42 用两个栈实现队列.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-16
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
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }

        int res = stack2.top();
        stack2.pop();

        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack1.pop();
        }
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};