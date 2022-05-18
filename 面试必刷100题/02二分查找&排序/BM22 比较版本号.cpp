/**
 * @File Name: BM22 �Ƚϰ汾��.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-11
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
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * �Ƚϰ汾��
     * @param version1 string�ַ���
     * @param version2 string�ַ���
     * @return int����
     */
    int compare(string version1, string version2)
    {
        int n1 = version1.size();
        int n2 = version2.size();
        int i = 0, j = 0;

        while (i < n1 || j < n2)
        {
            long long num1 = 0;
            while (i < n1 && version1[i] != '.')
            {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            i++;
            long long num2 = 0;
            while (j < n2 && version2[j] != '.')
            {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            j++;

            if (num1 > num2)
                return 1;
            if (num1 < num2)
                return -1;
        }
        return 0;
    }
};