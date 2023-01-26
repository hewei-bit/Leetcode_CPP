/**
 * @File Name: BM32 ºÏ²¢¶þ²æÊ÷.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-06-06
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
     *
     * @param t1 TreeNode?
     * @param t2 TreeNode?
     * @return TreeNode?
     */
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        // write code here
        if (t1 == nullptr)
            return t2;
        if (t2 == nullptr)
            return t1;
        TreeNode *head = new TreeNode(t1->val + t2->val);
        head->left = mergeTrees(t1->left, t2->left);
        head->right = mergeTrees(t1->right, t2->right);
        return head;
    }
};