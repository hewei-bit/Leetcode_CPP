/**
 * @File Name: 勾股数元组.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-05
 *
 */

/*
如果3个正整数(a,b,c)满足a2 + b2 = c2的关系，则称(a,b,c)为勾股数（著名的勾三股四弦
五），为了探索勾股数的规律，我们定义如果勾股数(a,b,c)之间两两互质（即a与b，a与c，b与
c之间均互质，没有公约数），则其为勾股数元祖（例如(3,4,5)是勾股数元祖，(6,8,10)则不
是勾股数元祖）。请求出给定范围[N,M]内，所有的勾股数元祖。
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
