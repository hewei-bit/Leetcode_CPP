/**
 * @File Name: 49. ����.cpp
 * @Brief : ��̬�滮
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
#include <set>
#include <algorithm>

using namespace std;

// ���ǰ�ֻ���������� 2��3 �� 5 ��������������Ugly Number����
// �󰴴�С�����˳��ĵ� n ��������

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int a = 0, b = 0, c = 0;
        int dp[n];
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
            dp[i] = min(min(n2, n3), n5);
            if (dp[i] == n2)
                a++;
            if (dp[i] == n3)
                b++;
            if (dp[i] == n5)
                c++;
        }
        return dp[n - 1];
    }
};