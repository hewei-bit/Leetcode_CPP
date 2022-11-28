/**
 * @File Name: BM14 ��������ż����.cpp
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
    ListNode *oddEvenList(ListNode *head)
    {
        // 如果链表为空不用重排
        if (head == NULL)
            return head;
        ListNode *even = head->next;
        ListNode *odd = head;
        ListNode *evenHead = even;
        while (even != NULL && even->next != NULL)
        {
            // odd连接even的后一个位，奇数位
            odd->next = even->next;
            // odd进入后一个奇数位
            odd = odd->next;
            // even连接后一个奇数位的后一位，偶数位
            even->next = odd->next;
            // even进入后一个偶数位
            even = even->next;
        }
        // even整体接在odd后面
        odd->next = evenHead;
        return head;
    }
};