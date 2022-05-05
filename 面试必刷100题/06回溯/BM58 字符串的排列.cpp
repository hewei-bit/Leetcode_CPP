/**
 * @File Name: BM58 ×Ö·û´®µÄÅÅÁÐ.cpp
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
    void DFS(string &str, vector<int> &vis, vector<string> &res, string &temp)
    {
        if (temp.size() == str.size())
            res.push_back(temp);

        for (int i = 0; i < str.size(); i++)
        {
            if (vis[i])
                continue;
            if (i > 0 && str[i - 1] == str[i] && !vis[i - 1])
                continue;
            vis[i] = 1;
            temp.push_back(str[i]);

            DFS(str, vis, res, temp);

            vis[i] = 0;
            temp.pop_back();
        }
    }

    vector<string> Permutation(string str)
    {
        sort(str.begin(), str.end());
        vector<int> vis(str.size(), 0);
        vector<string> res;
        string temp;
        DFS(str, vis, res, temp);
        return res;
    }
};