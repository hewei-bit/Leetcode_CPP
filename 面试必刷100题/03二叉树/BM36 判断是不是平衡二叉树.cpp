/**
 * @File Name: BM36 判断是不是平衡二叉树.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-15
 *
 */

#include <iostream>

#include <queue>
#include <stack>
#include <unordered_map>

#include <cmath>

#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return true;
        int left = deep(pRoot->left);
        int right = deep(pRoot->right);

        if (left - right > 1 || right - left > 1)
            return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }

    int deep(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = deep(root->left);
        int right = deep(root->right);

        return (left > right) ? left + 1 : right + 1;
    }
};