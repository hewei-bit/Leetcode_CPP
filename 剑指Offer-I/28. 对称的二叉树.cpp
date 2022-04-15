/**
 * @File Name: 28. ¶Ô³ÆµÄ¶þ²æÊ÷.cpp
 * @Brief : DFS µÝ¹é
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
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *L, TreeNode *R)
    {
        if (L == nullptr && R == nullptr)
            return true;
        if (!L || !R || L->val != R->val)
            return false;
        return isSymmetric(L->left, R->right) && isSymmetric(L->right, R->left);
    }
};