/**
 * @File Name: BM55 没有重复项数字的全排列.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-27
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
    vector<vector<int>> permute(vector<int> &num)
    {
        vector<int> cur;
        vector<bool> used(num.size(), false);
        dfs(num, cur, used);

        for (auto &i : tmp)
        {
            res.push_back(i);
        }

        return res;
    }

private:
    vector<vector<int>> res;
    set<vector<int>> tmp;
    void dfs(vector<int> &num, vector<int> cur, vector<bool> &used)
    {
        if (cur.size() == num.size())
        {
            tmp.insert(cur);
            return;
        }

        for (int i = 0; i < num.size(); i++)
        {
            if (used[i])
                continue;

            cur.push_back(num[i]);
            used[i] = true;

            dfs(num, cur, used);

            used[i] = false;
            cur.pop_back();
        }
    }
};