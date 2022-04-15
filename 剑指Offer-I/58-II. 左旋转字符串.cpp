/**
 * @File Name: 58-II. ×óÐý×ª×Ö·û´®.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-15
 *
 */
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        // for(int i = 0;i < n;i++)
        // {
        //     s.push_back(s[i]);
        // }
        // s.erase(0, n);
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};