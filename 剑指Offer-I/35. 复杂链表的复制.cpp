/**
 * @File Name: 35. ��������ĸ���.cpp
 * @Brief :  ��ϣ��
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-14
 *
 */

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

/*
// Definition for a Node.
*/

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
#if 1
    // ��1����ϣ��
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return NULL;
        Node *cur = head;
        unordered_map<Node *, Node *> Node_Map;
        // 3. ���Ƹ��ڵ㣬������ ��ԭ�ڵ� -> �½ڵ㡱 �� Map ӳ��
        while (cur != nullptr)
        {
            Node_Map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        // 4. ����������� next �� random ָ��
        while (cur != nullptr)
        {
            Node_Map[cur]->next = Node_Map[cur->next];
            Node_Map[cur]->random = Node_Map[cur->random];
            cur = cur->next;
        }
        // 5. �����������ͷ�ڵ�
        return Node_Map[head];
    }
#elif 0
    // ��2��ƴ�ӼӲ��
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return NULL;
        Node *cur = head;
        // 1. ���Ƹ��ڵ㣬������ƴ������
        while (cur != nullptr)
        {
            Node *tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }

        // 2. �������½ڵ�� random ָ��
        cur = head;
        while (cur != nullptr)
        {
            if (cur->random != nullptr)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        // 3. ���������
        cur = head->next;
        Node *pre = head, *res = head->next;
        while (cur->next != nullptr)
        {
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr;
        return res;
    }

#endif
};