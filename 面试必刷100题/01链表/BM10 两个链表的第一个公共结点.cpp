/**
 * @File Name: BM10 两个链表的第一个公共结点.cpp
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
    int ListLength(ListNode *pHead)
    {
        ListNode *p = pHead;
        int n = 0;
        while (p != nullptr)
        {
            n++;
            p = p->next;
        }
        return n;
    }
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == nullptr || pHead2 == nullptr)
        {
            return nullptr;
        }
        ListNode *pA = pHead1, *pB = pHead2;
        while (pA != pB)
        {
            pA = pA == nullptr ? pHead2 : pA->next;
            pB = pB == nullptr ? pHead1 : pB->next;
        }
        return pA;
    }
};