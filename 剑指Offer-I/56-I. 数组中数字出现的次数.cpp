/**
 * @File Name: 56 - I. ���������ֳ��ֵĴ���.cpp
 * @Brief : ��ѧ
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
// һ���������� nums �����������֮�⣬�������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
// Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��
class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        int x = 0, y = 0, n = 0, m = 1;
        for (int num : nums)
            n ^= num; // 1. �������
        while ((n & m) == 0)
            m <<= 1;         // 2. ѭ�����ƣ����� m
        for (int num : nums) // 3. ���� nums ����
        {
            if (num & m)
                x ^= num;
            else
                y ^= num;
        }
        return vector<int>{x, y}; // 5. ���س���һ�ε�����
    }
};