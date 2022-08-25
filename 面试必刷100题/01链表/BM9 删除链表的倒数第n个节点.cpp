/**
 * @File Name: BM9 ɾ������ĵ�����n���ڵ�.cpp
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
     * @param head ListNode��
     * @param n int����
     * @return ListNode��
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
        // ɾ����λ�õĽڵ�
        pre->next = cur->next;
        // ����ȥ��ͷ
        return res->next;
    }
};