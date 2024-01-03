/**
 * @File Name: BM86 �����ӷ�.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2023-04-22
 *
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <set>
#include <string>

using namespace std;
class Solution
{
public:
    string solve(string s, string t)
    {
        if (s.empty())
            return t;
        if (t.empty())
            return s;
        // ��s�ϳ� t�϶�
        if (s.length() < t.length())
            swap(s, t);
        // ��λ��־
        int carry = 0;
        // �Ӻ���ǰ��
        for (int i = s.length() - 1; i >= 0; i--)
        {
            // ת���ּ��Ͻ�λ
            int temp = s[i] - '0' + carry;
            // ��ý϶��ַ������±�
            int j = i - s.length() + t.length();
            // ����϶��ַ�������
            if (j >= 0)
                temp += t[j] - '0';
            carry = temp / 10;
            temp = temp % 10;
            // �޸Ľ��
            s[i] = temp + '0';
        }
        // ����λ
        if (carry == 1)
            s = '1' + s;
        return s;
    }
};