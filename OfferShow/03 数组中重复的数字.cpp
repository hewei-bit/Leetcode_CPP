/**
 * @File Name: 03 �������ظ�������.cpp
 * @Brief : ��ϣ��
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-13
 *
 */

// �ҳ��������ظ������֡�
// ��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�
// ������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ�
// ���ҳ�����������һ���ظ������֡�

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        unordered_map<int, bool> res;
        for (int num : nums)
        {
            if (res[num])
                return num;
            res[num] = true;
        }
        return -1;
    }
};