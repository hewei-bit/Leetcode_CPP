/**
 * @File Name: 25. 合并两个排序的链表.cpp
 * @Brief : 递归、链表
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-14
 *
 */

/**
 * Definition for singly-linked list.
 */

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        //    if(l1 == nullptr) return l2;
        //     if(l2 == nullptr) return l1;
        //     if(l1->val <= l2->val) {
        //         l1->next = mergeTwoLists(l1->next, l2);
        //         return l1;
        //     } else {
        //         l2->next = mergeTwoLists(l1, l2->next);
        //         return l2;
        //     }

        ListNode *dum = new ListNode(0);
        ListNode *cur = dum;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 != nullptr ? l1 : l2;
        return dum->next;
    }
};