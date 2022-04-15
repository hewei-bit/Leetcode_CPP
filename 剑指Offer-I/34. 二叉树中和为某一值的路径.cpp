/**
 * @File Name: 33. �����������ĺ����������.cpp
 * @Brief : �ݹ�
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
        // ��ֹ����
        if (root == nullptr)
            return;

        // ���·��
        path.push_back(root->val);
        target -= root->val;

        //���ϼ�¼·��
        if (target == 0 && root->left == nullptr && root->right == nullptr)
            res.push_back(path);

        DFS(root->left, target);
        DFS(root->right, target);

        // ·���ָ�
        path.pop_back();
    }
};