/**
 * @File Name: 68-II. �������������������.cpp
 * @Brief : DFS
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
/**
 * Definition for a binary tree node.
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root == p || root == q)
            return root; // ��� p��q���е��� root�ģ���ô���ǵ�����������ȼ�Ϊroot��һ���ڵ�Ҳ���������Լ������ȣ�

        TreeNode *left = lowestCommonAncestor(root->left, p, q); // �ݹ������������ֻҪ�����������ҵ���p��q�������ҵ�˭�ͷ���˭

        TreeNode *right = lowestCommonAncestor(root->right, p, q); // �ݹ������������ֻҪ�����������ҵ���p��q�������ҵ�˭�ͷ���˭

        if (left == nullptr && right == nullptr)
            return nullptr; // ������������� p�� q���Ҳ������� p�� qһ�������������У����������ȱ��������Ǹ���������������ȣ�һ���ڵ�Ҳ���������Լ������ȣ�

        // ������� left��Ϊ�գ��������������ҵ��ڵ㣨p��q������ʱ��Ҫ���ж�һ���������е������������������У�p��q���Ҳ������� p��qһ�������������У����������ȱ��������Ǹ���������������ȣ�һ���ڵ�Ҳ���������Լ������ȣ�
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;

        //���򣬵� left�� right����Ϊ��ʱ��˵�� p��q�ڵ�ֱ��� root���, ����������ȼ�Ϊ root
        return root;
    }
};