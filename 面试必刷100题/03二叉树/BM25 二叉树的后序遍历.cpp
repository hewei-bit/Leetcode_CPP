/**
 * @File Name: BM25 二叉树的后序遍历.cpp
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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型vector
     */
    vector<int> postorderTraversal(TreeNode *root)
    {
        TreeNode *p = root;
        vector<int> ret;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        if (p != nullptr)
        {
            s1.push(p); // 头结点先压入s1中
        }
        while (!s1.empty())
        {
            p = s1.top(); // 每次从s1中弹出一个结点
            s1.pop();     // 弹出的结点压入s2中
            s2.push(p);

            if (p->left != nullptr)
            { // 先压左
                s1.push(p->left);
            }
            if (p->right != nullptr)
            {
                s1.push(p->right); // 再压右
            }
        }

        // 这样s1的顺序就是 根右左，s2的顺序就是左右根
        while (!s2.empty())
        {
            ret.push_back(s2.top()->val);
            s2.pop();
        }
        return ret;
    }
};