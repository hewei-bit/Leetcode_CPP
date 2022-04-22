/**
 * @File Name: 44. ����������ĳһλ������.cpp
 * @Brief : ���ֲ���
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
// 1.�� 101112 101112? �е�ÿһλ��Ϊ ��λ ����Ϊ n ��
// 2.�� 10, 11, 12, 10,11,12,? ��Ϊ ���� ����Ϊ num ��
// 3.���� 1010 ��һ����λ�����ƴ����ֵ� λ�� Ϊ 22 ����Ϊ digit ��
// 4.ÿ digitdigit λ������ʼ���֣�����1, 10, 100, 1,10,100,?������Ϊ start

class Solution
{
public:
    int findNthDigit(int n)
    {
        int digit = 1;
        long start = 1;
        long count = 9;
        while (n > count)
        {
            n -= count;
            digit += 1;
            start *= 10;
            count = digit * start * 9;
        }

        long num = start + (n - 1) / digit;

        count = (n - 1) % digit;
        string s = to_string(num);
        int ans = s[count] - '0';

        return ans;
    }
};