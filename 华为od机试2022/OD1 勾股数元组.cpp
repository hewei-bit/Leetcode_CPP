/**
 * @File Name: ������Ԫ��.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-05
 *
 */

/*
���3��������(a,b,c)����a2 + b2 = c2�Ĺ�ϵ�����(a,b,c)Ϊ�������������Ĺ���������
�壩��Ϊ��̽���������Ĺ��ɣ����Ƕ������������(a,b,c)֮���������ʣ���a��b��a��c��b��
c֮������ʣ�û�й�Լ����������Ϊ������Ԫ�棨����(3,4,5)�ǹ�����Ԫ�棬(6,8,10)��
�ǹ�����Ԫ�棩�������������Χ[N,M]�ڣ����еĹ�����Ԫ�档
*/

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>

#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    void GouGu()
    {
        int n, m;
        cout << "please input" << endl;
        cin >> n;
        cin >> m;
        // n = 1;
        // m = 20;
        int count = 0;
        try
        {
            for (int i = n; i < m; i++)
            {
                for (int j = n + 1; j < m; j++)
                {
                    for (int k = n + 2; k < m; k++)
                    {
                        if (i < j && j < k && k * k == i * i + j * j && HuZhi(i, j) == 1 && HuZhi(j, k) == 1 && HuZhi(i, k) == 1)
                        {
                            cout << i << " " << j << " " << k << endl;
                            count++;
                        }
                    }
                }
            }
        }
        catch (...)
        {
        }

        if (count == 0)
        {
            cout << "Na" << endl;
        }
    }

    int HuZhi(int a, int b)
    {
        if (a == 0 || b == 0)
            return 1;
        if (a % b == 0)
            return b;
        else
            return HuZhi(b, a % b);
    }
};

int main()
{
    Solution ss;
    ss.GouGu();
    return 0;
}
