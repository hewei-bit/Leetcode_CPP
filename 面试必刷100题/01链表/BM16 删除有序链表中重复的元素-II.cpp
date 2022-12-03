/**
 * @File Name: BM16 ɾ�������������ظ���Ԫ��-II.cpp
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

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    // write code here
    if (head == NULL)
        return NULL;
    ListNode *res = new ListNode(0);
    // ������ǰ���һ��ͷ
    res->next = head;
    ListNode *cur = res;
    while (cur->next != NULL && cur->next->next != NULL)
    {
        // �������������ڵ�ֵ��ͬ
        if (cur->next->val == cur->next->next->val)
        {
            int temp = cur->next->val;
            // ������ͬ������
            while (cur->next != NULL && cur->next->val == temp)
            {
                cur->next = cur->next->next;
            }
        }
        else
        {
            cur = cur->next;
        }
    }
    return res->next;
}