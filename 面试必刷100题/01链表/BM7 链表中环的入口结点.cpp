/**
 * @File Name: BM7 �����л�����ڽ��.cpps
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
        // û�л�
        if (slow == nullptr)
            return nullptr;
        // ��ָ���ͷ
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
        // �ж�����Ϊ�յ����
        if (pHead == nullptr)
            return nullptr;
        // ����ָ��
        ListNode *slow = pHead;
        ListNode *fast = pHead;
        // ���û����ָ����ȵ���β
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return slow;
        }
        // ��ĩβ����û�л�
        return nullptr;
    }
};