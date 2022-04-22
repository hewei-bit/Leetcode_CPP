/**
 * @File Name: 55 - II. 平衡二叉树.cpp
 * @Brief : DFS
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

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        // 方法一：先序遍历+判断深度
        if (root == nullptr)
            return true;
        return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        // 方法二：后序遍历
        // return dfs(root) == -1 ? false :true;
    }

private:
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = dfs(root->left);
        if (left == -1)
            return -1;
        int right = dfs(root->right);
        if (right == -1)
            return -1;
        return abs(right - left) < 2 ? max(left, right) + 1 : -1;
    }

    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};