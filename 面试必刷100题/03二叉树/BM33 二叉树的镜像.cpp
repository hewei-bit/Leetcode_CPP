/**
 * @File Name: BM33 ¶þ²æÊ÷µÄ¾µÏñ.cpp
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
     * ????????????????????????????????????
     *
     *
     * @param pRoot TreeNode?
     * @return TreeNode?
     */
    TreeNode *Mirror(TreeNode *pRoot)
    {
        // write code here
        if (pRoot == nullptr)
            return nullptr;
        TreeNode *left = Mirror(pRoot->left);
        TreeNode *right = Mirror(pRoot->right);

        pRoot->left = right;
        pRoot->right = left;
        return pRoot;
    }
};