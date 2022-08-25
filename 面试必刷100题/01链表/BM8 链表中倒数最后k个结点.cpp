/**
 * @File Name: BM8 链表中倒数最后k个结点.cpp
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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode *FindKthToTail(ListNode *pHead, int k)
    {
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        //
        for (int i = 0; i < k; i++)
        {
            if (fast != nullptr)
                fast = fast->next;
            else
                return slow = nullptr;
        }
        //
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};