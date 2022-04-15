/**
 * @File Name: 07 �ؽ�������.cpp
 * @Brief : ���Σ�������
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
        // �����������ù�ϣ��洢�����ڲ��Ҹ��ڵ�
        for (int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;
        // ���������ǰ��,����ǰ�����и��ڵ㣬����������߽磬���������ұ߽�
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