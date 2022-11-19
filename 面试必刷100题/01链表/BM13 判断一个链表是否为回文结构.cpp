/**
 * @File Name: BM13 判断一个链表是否为回文结构.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-06-06
 *
 */

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
public:
    ListNode *Reverse(ListNode *head)
    {
        // 前序节点
        ListNode *prev = NULL;
        while (head != NULL)
        {
            ListNode *tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
    bool isPail(ListNode *head)
    {
        // 空链表直接为回文
        if (head == NULL)
        {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        // 双指针找中点
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 中点处反转
        slow = Reverse(slow);
        fast = head;
        while (slow != NULL)
        {
            if (slow->val != fast->val)
            {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};