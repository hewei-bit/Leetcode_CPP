/**
 * @File Name: BM10 ��������ĵ�һ���������.cpp
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
        int p1 = ListLength(pHead1);
        int p2 = ListLength(pHead1);
        // ���p1�Ƚϳ�
        if (p1 >= p2)
        {
            int n = p1 - p2;
            for (int i = 0; i < n; i++)
            {
                pHead1 = pHead1->next;
            }
            // ��������ͬʱ�ƶ�
            while ((pHead1 != nullptr) && (pHead2 != nullptr) && (pHead1 != pHead2))
            {
                pHead1 = pHead1->next;
                pHead2 = pHead2->next;
            }
        }
        // ���p2�Ƚϳ�
        else
        {
            int n = p2 - p1;
            for (int i = 0; i < n; i++)
            {
                pHead2 = pHead2->next;
            }
            //
            while ((pHead1 != nullptr) && (pHead2 != nullptr) && (pHead1 != pHead2))
            {
                pHead1 = pHead1->next;
                pHead2 = pHead2->next;
            }
        }
        return pHead1;
    }
};