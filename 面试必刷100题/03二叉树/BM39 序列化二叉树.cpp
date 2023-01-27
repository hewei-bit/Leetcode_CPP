/**
 * @File Name: BM39 ÐòÁÐ»¯¶þ²æÊ÷.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2023-01-27
 *
 */

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
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
    void SerializaFunction(TreeNode *root, string &str)
    {
        if (root == nullptr)
        {
            str += '#';
            return;
        }

        string temp = to_string(root->val);

        str += temp + '!';

        SerializaFunction(root->left, str);
        SerializaFunction(root->right, str);
    }
    char *Serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "#";
        string res;
        SerializaFunction(root, res);

        char *charRes = new char[res.length() + 1];
        strcpy(charRes, res.c_str());
        charRes[res.length()] = ' ';
        return charRes;
    }
    TreeNode *DeserializaFunction(char **str)
    {
        if (**str == '#')
        {
            (*str)++;
            return nullptr;
        }

        int val = 0;
        while (**str != '!' && **str != ' ')
        {
            val = val * 10 + ((**str) - '0');
            (*str)++;
        }

        TreeNode *root = new TreeNode(val);

        if (**str == ' ')
            return root;
        else
            (*str)++;

        root->left = DeserializaFunction(str);
        root->right = DeserializaFunction(str);
        return root;
    }
    TreeNode *Deserialize(char *str)
    {
        if (str == "#")
        {
            return nullptr;
        }
        TreeNode *res = DeserializaFunction(&str);
        return res;
    }
};