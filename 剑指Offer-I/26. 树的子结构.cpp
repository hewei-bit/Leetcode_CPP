/**
 * @File Name: 26. 树的子结构.cpp
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
        //这个函数对这棵树进行前序遍历：即处理根节点，再递归左子节点，再递归处理右子节点
        //特殊情况是：当A或B是空树的时候 返回false
        //用||关系可以达到 不同顺序遍历的作用
        if (A == nullptr || B == nullptr)
            return false;
        return isContain(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool isContain(TreeNode *A, TreeNode *B)
    {
        //结束条件
        //当最后一层B已经为空的，证明则B中节点全是A中节点
        if (B == nullptr)
        {
            return true;
        }
        //这里因为有上一个条件，则说明 A已经为空了，B却不为空，则一定不是子数
        if (A == nullptr)
        {
            return false;
        }

        //处理本次递归，即处理当前节点
        if (A->val != B->val)
        {
            return false;
        }
        //递归，同时递归左右两个子节点
        return isContain(A->left, B->left) && isContain(A->right, B->right);
    }
};