/**
 * @File Name: 54. 二叉搜索树的第k大节点.cpp
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
    int res, k;
    int kthLargest(TreeNode *root, int k)
    {
        this->k = k;
        dfs(root);
        return res;
    }

private:
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        dfs(root->right);

        if (k == 0)
            return;
        if (--k == 0)
            res = root->val;

        dfs(root->left);
    }
};