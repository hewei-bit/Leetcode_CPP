/**
 * @File Name: 33. 二叉搜索树的后序遍历序列.cpp
 * @Brief : 递归
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
        // 终止条件
        if (l >= r)
            return true;
        // 找出左右子树
        int i;
        // 左子树会比根节点小
        for (i = r; i >= l; i--)
        {
            if (postorder[i] < postorder[r])
                break;
        }
        // 右子树会比根节点大
        for (int j = i; j >= l; j--)
        {
            if (postorder[j] > postorder[r])
                return false;
        }
        // 继续分别搞左右子树
        return verifyOrder(postorder, l, i) && verifyOrder(postorder, i + 1, r - 1);
    }
#endif
};