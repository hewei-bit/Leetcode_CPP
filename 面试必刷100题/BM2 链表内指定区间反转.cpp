/**
 * @File Name: BM2 链表内指定区间反转.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-23
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
    /**
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode *res = new ListNode(-1);
        res->next = head;

        ListNode *pre = res;
        ListNode *cur = head;

        for (int i = 0; i < m - 1; i++)
        {
            pre = cur;
            cur = cur->next;
        }

        for (int i = m; i < n; i++)
        {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }

        return res->next;
    }
};