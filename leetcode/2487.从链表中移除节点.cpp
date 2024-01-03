/**
 * @File Name: 2487.从链表中移除节点.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2024-01-03
 *
 */
#include <iostream>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        vector<int> nums;
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        vector<int> stk;
        for (int i : nums)
        {
            while (!stk.empty() && stk.back() < i)
            {
                stk.pop_back();
            }
            stk.push_back(i);
        }

        ListNode *dummy = new ListNode();
        head = dummy;
        for (int v : stk)
        {
            head->next = new ListNode(v);
            head = head->next;
        }

        return dummy->next;
    }
};