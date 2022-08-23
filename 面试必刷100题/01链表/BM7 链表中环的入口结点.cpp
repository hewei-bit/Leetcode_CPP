/**
 * @File Name: BM7 链表中环的入口结点.cpps
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-06-01
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
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        ListNode *slow = hasCycle(pHead);
        // 没有环
        if (slow == nullptr)
            return nullptr;
        // 快指针回头
        ListNode *fast = pHead;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode *hasCycle(ListNode *pHead)
    {
        // 判断链表为空的情况
        if (pHead == nullptr)
            return nullptr;
        // 快慢指针
        ListNode *slow = pHead;
        ListNode *fast = pHead;
        // 如果没环快指针会先到队尾
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return slow;
        }
        // 到末尾就是没有环
        return nullptr;
    }
};