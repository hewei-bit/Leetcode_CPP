/**
 * @File Name: 09 用两个栈实现队列.cpp
 * @Brief : 栈、队列
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-13
 *
 */
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class CQueue
{
public:
    stack<int> preStack;
    stack<int> printStack;

    CQueue()
    {
    }

    void appendTail(int value)
    {
        preStack.push(value);
    }

    int deleteHead()
    {
        if (preStack.empty())
            return -1;

        while (!preStack.empty())
        {
            int tmp = preStack.top();
            preStack.pop();
            printStack.push(tmp);
        }

        int res = printStack.top();
        printStack.pop();

        while (!printStack.empty())
        {
            int temp = printStack.top();
            printStack.pop();
            preStack.push(temp);
        }
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */