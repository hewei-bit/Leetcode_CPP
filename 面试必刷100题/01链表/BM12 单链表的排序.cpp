/**
 * @File Name: BM12 µ¥Á´±íµÄÅÅÐò.cpp
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
    ListNode *merge(ListNode *pHead1, ListNode *pHead2)
    {
        // ?????????????
        if (pHead1 == nullptr)
            return pHead1;
        if (pHead2 == nullptr)
            return pHead2;
        // ?????
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        // ?????????
        while (pHead1 && pHead2)
        {
            // ???????
            if (pHead1->val <= pHead2->val)
            {
                cur->next = pHead1;
                // ????????
                pHead1 = pHead1->next;
            }
            else
            {
                cur->next = pHead2;
                // ????????
                pHead2 = pHead2->next;
            }
            // ?????
            cur = cur->next;
        }
        // ??????????????
        if (pHead1)
            cur->next = pHead1;
        else
            cur->next = pHead2;

        return head->next;
    }
    ListNode *sortInList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *left = head;
        ListNode *mid = head->next;
        ListNode *right = head->next->next;
        // ??????????????????????
        while (right != NULL && right->next != NULL)
        {
            left = left->next;
            mid = mid->next;
            right = right->next->next;
        }
        // ???????????????
        left->next = NULL;
        // ??????
        return merge(sortInList(head), sortInList(mid));
    }
};