/**
 * @File Name: 26. �����ӽṹ.cpp
 * @Brief : DFS
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
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        //������������������ǰ���������������ڵ㣬�ٵݹ����ӽڵ㣬�ٵݹ鴦�����ӽڵ�
        //��������ǣ���A��B�ǿ�����ʱ�� ����false
        //��||��ϵ���Դﵽ ��ͬ˳�����������
        if (A == nullptr || B == nullptr)
            return false;
        return isContain(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool isContain(TreeNode *A, TreeNode *B)
    {
        //��������
        //�����һ��B�Ѿ�Ϊ�յģ�֤����B�нڵ�ȫ��A�нڵ�
        if (B == nullptr)
        {
            return true;
        }
        //������Ϊ����һ����������˵�� A�Ѿ�Ϊ���ˣ�Bȴ��Ϊ�գ���һ����������
        if (A == nullptr)
        {
            return false;
        }

        //�����εݹ飬������ǰ�ڵ�
        if (A->val != B->val)
        {
            return false;
        }
        //�ݹ飬ͬʱ�ݹ����������ӽڵ�
        return isContain(A->left, B->left) && isContain(A->right, B->right);
    }
};