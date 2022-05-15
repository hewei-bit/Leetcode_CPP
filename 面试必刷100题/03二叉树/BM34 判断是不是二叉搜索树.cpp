/**
 * @File Name: BM34 �ж��ǲ��Ƕ���������.cpp
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
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param root TreeNode��
     * @return bool������
     */
    long pre = INT_MIN;
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        if (!isValidBST(root->left))
            return false;

        if (root->val <= pre)
            return false;
        pre = root->val;

        if (!isValidBST(root->right))
            return false;
        return true;
    }
};