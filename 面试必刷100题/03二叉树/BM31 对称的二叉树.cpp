/**
 * @File Name: BM31 ¶Ô³ÆµÄ¶þ²æÊ÷.cpp
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
    bool recursion(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        if (root1 == nullptr || root2 == nullptr || root1->val != root2->val)
            return false;
        return recursion(root1->left, root2->right) && recursion(root1->right, root2->left);
    }
    bool isSymmetrical(TreeNode *pRoot)
    {
        return recursion(pRoot, pRoot);
    }
};