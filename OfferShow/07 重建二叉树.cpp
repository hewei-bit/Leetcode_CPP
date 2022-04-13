/**
 * @File Name: 07 重建二叉树.cpp
 * @Brief : 分治，二叉树
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-13
 *
 */
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    unordered_map<int, int> map;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 将中序序列用哈希表存储，便于查找根节点
        for (int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;
        // 传入参数：前序,中序，前序序列根节点，中序序列左边界，中序序列右边界
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int pre_root, int in_left, int in_right)
    {
        if (in_left > in_right)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[pre_root]);

        int in_root = map[preorder[pre_root]];

        root->left = build(preorder, inorder, pre_root + 1, in_left, in_root - 1);

        root->right = build(preorder, inorder, pre_root + (in_root - in_left) + 1, in_root + 1, in_right);

        return root;
    }
};