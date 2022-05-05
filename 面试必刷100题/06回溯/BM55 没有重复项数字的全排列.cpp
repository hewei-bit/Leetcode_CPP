/**
 * @File Name: BM55 没有重复项数字的全排列.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-01
 *
 */
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &num)
    {
        vector<int> tmp;
        vector<bool> used(num.size(), false);
        vector<vector<int>> res;

        dfs(num, res, tmp, used);

        return res;
    }

private:
    void dfs(vector<int> &num, vector<vector<int>> &res,
             vector<int> &tmp, vector<bool> &used)
    {
        if (tmp.size() == num.size())
        {
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i < num.size(); i++)
        {
            if (used[i])
                continue;

            tmp.push_back(num[i]);
            used[i] = true;

            dfs(num, res, tmp, used);

            used[i] = false;
            tmp.pop_back();
        }
    }
};