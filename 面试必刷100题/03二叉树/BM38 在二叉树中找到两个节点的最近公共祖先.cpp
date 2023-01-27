/**
 * @File Name: BM38 �ڶ��������ҵ������ڵ�������������.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2023-01-27
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
    bool flag = false;
    void dfs(TreeNode *root, vector<int> &path, int o)
    {
        if (flag || root == nullptr)
            return;
        path.push_back(root->val);
        // �ҵ��ڵ�
        if (root->val == o)
        {
            flag = true;
            return;
        }

        dfs(root->left, path, o);
        dfs(root->right, path, o);
        if (flag)
            return;

        path.pop_back();
    }
    /**
     *
     * @param root TreeNode��
     * @param o1 int����
     * @param o2 int����
     * @return int����
     */
    int lowestCommonAncestor(TreeNode *root, int o1, int o2)
    {
        // write code here
        vector<int> path1, path2;
        // ����ڵ㵽�����ڵ��·��
        dfs(root, path1, o1);
        flag = false;
        dfs(root, path2, o2);
        int res;

        for (int i = 0; i < path1.size() && i < path2.size(); i++)
        {
            if (path1[i] == path2[i])
                res = path1[i];
            else
                break;
        }
        return res;
    }
};