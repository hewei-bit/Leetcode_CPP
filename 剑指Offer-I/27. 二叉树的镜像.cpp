/**
 * @File Name: 27. �������ľ���.cpp
 * @Brief : DFS �ݹ�
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

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *mirrorTree(TreeNode *root)
    {
        // �ݹ�
        if (root == nullptr)
            return nullptr;

        TreeNode *tmp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmp);

        return root;

        // ����ջ
        // if(root == nullptr)
        //     return nullptr;

        // stack<TreeNode* > s;
        // s.push(root);
        // TreeNode res(root->val);

        // while(s.size()){

        //     TreeNode *node = s.top();
        //     s.pop();

        //     if(node->left)
        //     {
        //         s.push(node->left);
        //     }
        //     if(node->right)
        //     {
        //         s.push(node->right);
        //     }

        //     TreeNode * tmp = node->left;
        //     node->left = node->right;
        //     node->right = tmp;

        // }
        // return root;
    }
};