/**
 * @File Name: 18 ɾ������Ľڵ�.cpp
 * @Brief : ˫ָ�롢����
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-13
 *
 */

// �������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣
// ����ɾ����������ͷ�ڵ㡣
// ע�⣺����Ա�ԭ���иĶ�
// ʾ�� 1:
// ����: head = [4,5,1,9], val = 5
// ���: [4,1,9]
// ����: ������������ֵΪ?5?�ĵڶ����ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 1 -> 9.

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>

using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        if (head->val == val)
            return head->next;
        ListNode *pre = head;
        ListNode *cur = head->next;
        while (cur != nullptr && cur->val != val)
        {
            pre = cur;
            cur = cur->next;
        }
        if (cur != nullptr)
            pre->next = cur->next;
        return head;
    }
};