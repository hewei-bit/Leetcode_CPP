/**
 * @File Name: 33. 二叉搜索树的后序遍历序列.cpp
 * @Brief : 递归
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
    vector<vector<int>> pathSum(TreeNode *root, int target)
    {
        DFS(root, target);
        return res;
    }

private:
    vector<int> path;
    vector<vector<int>> res;

    void DFS(TreeNode *root, int target)
    {
        // 终止条件
        if (root == nullptr)
            return;

        // 添加路径
        path.push_back(root->val);
        target -= root->val;

        //符合记录路径
        if (target == 0 && root->left == nullptr && root->right == nullptr)
            res.push_back(path);

        DFS(root->left, target);
        DFS(root->right, target);

        // 路径恢复
        path.pop_back();
    }
};