/**
 * @File Name: 38. �ַ���������.cpp
 * @Brief : DFS �����㷨
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
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> permutation(string s)
    {
        string cur = "";
        vector<bool> used(s.size(), false);

        dfs(s, cur, used);

        for (auto &i : tmp)
            res.push_back(i);

        return res;
    }

private:
    vector<string> res;
    set<string> tmp;

    void dfs(string &s, string &cur, vector<bool> &used)
    {
        // ��ֹ����
        if (cur.size() == s.size())
        {
            tmp.insert(cur);
            return;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (used[i])
                continue;

            cur += s[i];
            used[i] = true;

            dfs(s, cur, used);

            used[i] = false;
            cur.pop_back();
        }
    }
};