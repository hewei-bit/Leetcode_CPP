/**
 * @File Name: 06 ��β��ͷ��ӡ����.cpp
 * @Brief : ����ջ
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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        stack<int> helper;
        vector<int> res;
        ListNode *temp = head;
        while (temp != NULL)
        {
            helper.push(temp->val);
            temp = temp->next;
        }

        while (!helper.empty())
        {
            res.push_back(helper.top());
            helper.pop();
        }
        return res;
    }
};