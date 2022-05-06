/*
链接：https://ac.nowcoder.com/acm/contest/5657/D
来源：牛客网

输入描述:
输入数据包括多组。
每组数据一行,每行的第一个整数为整数的个数n(1 <= n <= 100), n为0的时候结束输入。
接下来n个正整数,即需要求和的每个正整数。
输出描述:
每组数据输出求和的结果
示例1
输入
4 1 2 3 4
5 1 2 3 4 5
0
输出
10
15
*/

#include <iostream>
using namespace std;
int main()
{
    int a, b;
    while (cin >> a)
    {
        int sum = 0;
        if (a == 0)
            break;
        for (int i = 0; i < a; i++)
        {
            cin >> b;

            sum += b;
        }
        cout << sum << endl;
    }
    return 0;
}