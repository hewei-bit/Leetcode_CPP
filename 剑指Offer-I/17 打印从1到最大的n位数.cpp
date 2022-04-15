/**
 * @File Name: 17 ��ӡ��1������nλ��.cpp
 * @Brief : DFS
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-13
 *
 */
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> printNumbers(int n)
    {
        s.resize(n, '0');
        dfs(n, 0);
        return nums;
    }
    // ö���������
    void dfs(int end, int index)
    {
        if (index == end)
        {
            save();
            return;
        }
        for (int i = 0; i <= 9; i++)
        {
            s[index] = i + '0';
            dfs(end, index + 1);
        }
    }
    // ȥ���ײ�0
    void save()
    {
        int ptr = 0;
        while (ptr < s.size() && s[ptr] == '0')
            ptr++;
        if (ptr != s.size())
            nums.emplace_back(stoi(s.substr(ptr)));
    }

private:
    vector<int> nums;
    string s;
};