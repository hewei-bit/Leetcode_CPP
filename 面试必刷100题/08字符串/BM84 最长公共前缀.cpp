/**
 * @File Name: BM84 �����ǰ׺.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-09
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
    /**
     *
     * @param strs string�ַ���vector
     * @return string�ַ���
     */
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        if (n == 0)
            return "";
        for (int i = 0; i < strs[0].length(); i++)
        {
            char temp = strs[0][i];
            for (int j = 1; j < n; j++)
            {
                if (i == strs[j].length() || temp != strs[j][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};