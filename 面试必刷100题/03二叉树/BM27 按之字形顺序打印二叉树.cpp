/**
 * @File Name: BM27 按之字形顺序打印二叉树.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-13
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
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> res;
        if (pRoot == nullptr)
            return res;

        queue<TreeNode *> q;
        q.push(pRoot);

        bool flag = true;

        while (!q.empty())
        {
            vector<int> temp;
            flag = !flag;

            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                temp.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (flag)
                reverse(temp.begin(), temp.end());
            res.push_back(temp);
        }
        return res;
    }
};