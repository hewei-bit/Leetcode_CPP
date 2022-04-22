/**
 * @File Name: 55 - I. 二叉树的深度.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-15
 *
 */

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>

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
    int maxDepth(TreeNode *root)
    {
        // DFS
        // 终止条件
        // if(root == nullptr) return 0;
        // return max(maxDepth(root->left),maxDepth(root->right))+1;

        // BFS
        int count = 0;
        if (root == nullptr)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            for (int i = q.size(); i > 0; i--)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            count++;
        }
        return count;
    }
};