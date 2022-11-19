/**
 * @File Name: BM13 �ж�һ�������Ƿ�Ϊ���Ľṹ.cpp
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
    ListNode *Reverse(ListNode *head)
    {
        // ǰ��ڵ�
        ListNode *prev = NULL;
        while (head != NULL)
        {
            ListNode *tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
    bool isPail(ListNode *head)
    {
        // ������ֱ��Ϊ����
        if (head == NULL)
        {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        // ˫ָ�����е�
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // �е㴦��ת
        slow = Reverse(slow);
        fast = head;
        while (slow != NULL)
        {
            if (slow->val != fast->val)
            {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};