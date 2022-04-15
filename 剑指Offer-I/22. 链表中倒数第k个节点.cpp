/**
 * @File Name: 22. 链表中倒数第k个节点.cpp
 * @Brief : 双指针
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
/**
 * Definition for singly-linked list.
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < k; i++)
        {
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};