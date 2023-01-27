/**
 * @File Name: BM37 二叉搜索树的最近公共祖先.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2023-01-27
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
    vector<int> getPath(TreeNode *root, int target)
    {
        vector<int> path;
        TreeNode *node = root;
        while (node->val != target)
        {
            path.push_back(node->val);

            if (target < node->val)
                node = node->left;
            else
                node = node->right;
        }
        path.push_back(node->val);
        return path;
    }
    int lowestCommonAncestor(TreeNode *root, int p, int q)
    {
        // write code here
        vector<int> path_q = getPath(root, q);
        vector<int> path_p = getPath(root, p);

        int res;

        for (int i = 0; i < path_p.size() && i < path_q.size(); i++)
        {
            if (path_p[i] == path_q[i])
                res = path_p[i];
            else
                break;
        }
        return res;
    }
};