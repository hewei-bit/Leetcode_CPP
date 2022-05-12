/**
 * @File Name: BM23 二叉树的前序遍历.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-12
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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型vector
     */
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *tmp = s.top();
            s.pop();
            res.push_back(tmp->val);
            if (tmp->right)
                s.push(tmp->right);
            if (tmp->left)
                s.push(tmp->left);
                }
        return res;
    }
};