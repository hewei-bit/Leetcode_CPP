/**
 * @File Name: 36. 二叉搜索树与双向链表.cpp
 * @Brief : DFS
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

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

/*
// Definition for a Node.
*/
class Solution
{
public:
    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        dfs(root);

        //
        head->left = pre;
        pre->right = head;
        return head;
    }

private:
    Node *pre, *head;
    // 中序遍历
    void dfs(Node *cur)
    {
        // 终止条件
        if (cur == nullptr)
            return;

        dfs(cur->left); // 左子树

        if (pre != nullptr)
        {
            pre->right = cur;
        }
        else
        {
            head = cur;
        }
        cur->left = pre;
        pre = cur;

        dfs(cur->right); // 右子树
    }
};