/**
 * @File Name: BM9 删除链表的倒数第n个节点.cpp
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
    /**
     *
     * @param head ListNode类
     * @param n int整型
     * @return ListNode类
     */
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        //
        ListNode *res = new ListNode(-1);
        res->next = head;
        //
        ListNode *pre = res;
        ListNode *cur = head;
        ListNode *fast = head;
        //
        while (n--)
            fast = fast->next;
        //
        while (fast != nullptr)
        {
            fast = fast->next;
            pre = cur;
            cur = cur->next;
        }
        // 删除该位置的节点
        pre->next = cur->next;
        // 返回去掉头
        return res->next;
    }
};