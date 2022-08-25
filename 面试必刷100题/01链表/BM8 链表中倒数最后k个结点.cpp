/**
 * @File Name: BM8 �����е������k�����.cpp
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
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param pHead ListNode��
     * @param k int����
     * @return ListNode��
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