/**
 * @File Name: 59-II. 队列的最大值.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-15
 *
 */
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;
class MaxQueue
{
private:
    queue<int> que;
    deque<int> deq;

public:
    MaxQueue()
    {
    }

    int max_value()
    {
        return deq.empty() ? -1 : deq.front();
    }
    // 用双端队列来保存第一和第二大的
    void push_back(int value)
    {
        que.push(value);
        while (!deq.empty() && deq.back() < value)
        {
            deq.pop_back();
        }
        deq.push_back(value);
    }

    int pop_front()
    {
        if (que.empty())
            return -1;
        int val = que.front();
        if (val == deq.front())
        {
            deq.pop_front();
        }
        que.pop();
        return val;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */