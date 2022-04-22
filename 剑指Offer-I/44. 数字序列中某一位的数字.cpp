/**
 * @File Name: 44. 数字序列中某一位的数字.cpp
 * @Brief : 二分查找
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
// 1.将 101112 101112? 中的每一位称为 数位 ，记为 n ；
// 2.将 10, 11, 12, 10,11,12,? 称为 数字 ，记为 num ；
// 3.数字 1010 是一个两位数，称此数字的 位数 为 22 ，记为 digit ；
// 4.每 digitdigit 位数的起始数字（即：1, 10, 100, 1,10,100,?），记为 start

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