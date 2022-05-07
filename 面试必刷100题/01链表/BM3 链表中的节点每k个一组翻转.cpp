/**
 * @File Name: BM3 链表中的节点每k个一组翻转.cpp
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
    /**
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 找到每次反转的尾部
        ListNode *tail = head;
        for (int i = 0; i < k; i++)
        {
            if (tail == nullptr)
                return head;
            tail = tail->next;
        }

        ListNode *pre = nullptr;
        ListNode *cur = head;

        //
        while (cur != tail)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        head->next = reverseKGroup(tail, k);
        return pre;
    }
};