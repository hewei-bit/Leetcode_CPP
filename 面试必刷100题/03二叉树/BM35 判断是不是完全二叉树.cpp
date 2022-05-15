/**
 * @File Name: BM35 �ж��ǲ�����ȫ������.cpp
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
    bool isCompleteTree(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = false;

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *cur = q.front();
                q.pop();

                if (cur == nullptr)
                    flag = true;
                else
                {
                    if (flag)
                        return false;
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }
        return true;
    }
};