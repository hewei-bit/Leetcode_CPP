/**
 * @File Name: 56 - II. ���������ֳ��ֵĴ��� II.cpp
 * @Brief : λ����
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

// ��һ������ nums �г�һ������ֻ����һ��֮�⣬�������ֶ����������Ρ�
// ���ҳ��Ǹ�ֻ����һ�ε����֡�
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // ����ͳ��
        vector<int> counts(32, 0);
        for (int num : nums)
        {
            for (int j = 0; j < 32; j++)
            {
                counts[j] += num & 1;
                num >>= 1;
            }
        }

        int res = 0, m = 3;
        for (int i = 0; i < 32; i++)
        {
            res <<= 1;
            res |= counts[31 - i] % m;
        }

        return res;
    }
};