/**
 * @File Name: BM5 �ϲ�k�������������.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-08
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
    ListNode *Merge_2(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == nullptr)
            return pHead2;
        if (pHead2 == nullptr)
            return pHead1;

        ListNode *head = new ListNode(0);
        ListNode *cur = head;

        while (pHead1 && pHead2)
        {
            if (pHead1->val <= pHead2->val)
            {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }

        if (pHead1)
        {
            cur->next = pHead1;
        }
        else
        {
            cur->next = pHead2;
        }

        return head->next;
    }

    ListNode *divideMerge(vector<ListNode *> &lists, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        else if (left == right)
        {
            return lists[left];
        }
        int mid = left + (right - left) / 2;
        return Merge_2(divideMerge(lists, left, mid), divideMerge(lists, mid + 1, right));
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return divideMerge(lists, 0, lists.size() - 1);
    }
};