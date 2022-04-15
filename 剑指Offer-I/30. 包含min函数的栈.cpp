/**
 * @File Name: 30. °üº¬minº¯ÊýµÄÕ».cpp
 * @Brief : Õ»
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

class MinStack
{
public:
    stack<int> n_stack;
    stack<int> min_stack;
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        n_stack.push(x);
        if (min_stack.empty() || x < min_stack.top())
        {
            min_stack.push(x);
        }
        else
        {
            min_stack.push(min_stack.top());
        }
    }

    void pop()
    {
        n_stack.pop();
        min_stack.pop();
    }

    int top()
    {
        return n_stack.top();
    }

    int min()
    {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */