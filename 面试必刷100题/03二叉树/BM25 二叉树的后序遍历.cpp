/**
 * @File Name: BM25 �������ĺ������.cpp
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
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param root TreeNode��
     * @return int����vector
     */
    vector<int> postorderTraversal(TreeNode *root)
    {
        TreeNode *p = root;
        vector<int> ret;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        if (p != nullptr)
        {
            s1.push(p); // ͷ�����ѹ��s1��
        }
        while (!s1.empty())
        {
            p = s1.top(); // ÿ�δ�s1�е���һ�����
            s1.pop();     // �����Ľ��ѹ��s2��
            s2.push(p);

            if (p->left != nullptr)
            { // ��ѹ��
                s1.push(p->left);
            }
            if (p->right != nullptr)
            {
                s1.push(p->right); // ��ѹ��
            }
        }

        // ����s1��˳����� ������s2��˳��������Ҹ�
        while (!s2.empty())
        {
            ret.push_back(s2.top()->val);
            s2.pop();
        }
        return ret;
    }
};