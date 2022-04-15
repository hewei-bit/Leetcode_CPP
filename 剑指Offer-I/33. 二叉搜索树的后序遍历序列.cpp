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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
#if 0
    bool verifyPostorder(vector<int> &postorder)
    {
    }
#elif 1
    bool verifyPostorder(vector<int> &postorder)
    {
        return verifyOrder(postorder, 0, postorder.size() - 1);
    }
    bool verifyOrder(vector<int> &postorder, int l, int r)
    {
        // ��ֹ����
        if (l >= r)
            return true;
        // �ҳ���������
        int i;
        // ��������ȸ��ڵ�С
        for (i = r; i >= l; i--)
        {
            if (postorder[i] < postorder[r])
                break;
        }
        // ��������ȸ��ڵ��
        for (int j = i; j >= l; j--)
        {
            if (postorder[j] > postorder[r])
                return false;
        }
        // �����ֱ����������
        return verifyOrder(postorder, l, i) && verifyOrder(postorder, i + 1, r - 1);
    }
#endif
};