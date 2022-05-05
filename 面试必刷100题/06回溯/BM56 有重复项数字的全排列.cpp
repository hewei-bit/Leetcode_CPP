/**
 * @File Name: BM56 有重复项数字的全排列.cpp
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
    vector<vector<int>> permuteUnique(vector<int> &num)
    {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        vector<int> tmp;
        vector<int> vis(num.size(), 0);
        DFS(res, num, tmp, vis);
        return res;
    }

    void DFS(vector<vector<int>> &res, vector<int> &num, vector<int> &tmp, vector<int> &vis)
    {

        if (tmp.size() == num.size())
        {
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i < num.size(); i++)
        {

            if (vis[i])
                continue;
            if (i > 0 && num[i - 1] == num[i] && !vis[i - 1])
                continue;
            vis[i] = 1;
            tmp.push_back(num[i]);

            DFS(res, num, tmp, vis);

            tmp.pop_back();
            vis[i] = 0;
        }
    }
};