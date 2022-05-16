/**
 * @File Name: BM43 °üº¬minº¯ÊýµÄÕ».cpp
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
    stack<int> s1;
    stack<int> s2;

public:
    void push(int value)
    {
        s1.push(value);

        if (s2.empty() || s2.top() > value)
            s2.push(value);
        else
            s2.push(s2.top());
    }
    void pop()
    {
        s1.pop();
        s2.pop();
    }
    int top()
    {
        return s1.top();
    }
    int min()
    {
        return s2.top();
    }
};