/**
 * @File Name: 35. 复杂链表的复制.cpp
 * @Brief :  哈希表
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
    // 法1：哈希表
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return NULL;
        Node *cur = head;
        unordered_map<Node *, Node *> Node_Map;
        // 3. 复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
        while (cur != nullptr)
        {
            Node_Map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        // 4. 构建新链表的 next 和 random 指向
        while (cur != nullptr)
        {
            Node_Map[cur]->next = Node_Map[cur->next];
            Node_Map[cur]->random = Node_Map[cur->random];
            cur = cur->next;
        }
        // 5. 返回新链表的头节点
        return Node_Map[head];
    }
#elif 0
    // 法2：拼接加拆分
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return NULL;
        Node *cur = head;
        // 1. 复制各节点，并构建拼接链表
        while (cur != nullptr)
        {
            Node *tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }

        // 2. 构建各新节点的 random 指向
        cur = head;
        while (cur != nullptr)
        {
            if (cur->random != nullptr)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        // 3. 拆分两链表
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