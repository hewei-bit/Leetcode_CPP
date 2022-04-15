/**
 * @File Name: 39. �����г��ִ�������һ�������.cpp
 * @Brief : ��ѧ
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-14
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

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // ����
        int x = 0, votes = 0, count = 0;
        for (int num : nums)
        {
            // �����ʱ������������
            if (votes == 0)
                x = num;
            votes += num == x ? 1 : -1;
        }
        // ������֤
        for (int num : nums)
        {
            if (num == x)
                count++;
        }
        return count > nums.size() / 2 ? x : 0;
    }
};