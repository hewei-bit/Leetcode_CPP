/**
 * @File Name: BM11 链表相加(二).cpp
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
    ListNode *ReverseList(ListNode *pHead1)
    {
        if (pHead1 == nullptr)
            return nullptr;
        ListNode *cur = pHead1;
        ListNode *pre = nullptr;

        while (cur != nullptr)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    ListNode *addInList(ListNode *head1, ListNode *head2)
    {
        // write code here
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;

        head1 = ReverseList(head1);
        head2 = ReverseList(head2);

        ListNode *res = new ListNode(-1);
        ListNode *head = res;
        int carry = 0;

        while (head1 != nullptr || head2 != nullptr || carry != 0)
        {
            //
            int val1 = head1 == nullptr ? 0 : head1->val;
            int val2 = head2 == nullptr ? 0 : head2->val;

            int tmp = val1 + val2 + carry;

            carry = tmp / 10;
            tmp %= 10;

            head->next = new ListNode(tmp);
            head = head->next;

            if (head1 != nullptr)
                head1 = head1->next;
            if (head2 != nullptr)
                head2 = head2->next;
        }
        return ReverseList(res->next);
    }
};