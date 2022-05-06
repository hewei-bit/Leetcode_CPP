/*
链接：https://ac.nowcoder.com/acm/contest/5657/B
来源：牛客网

输入描述:
输入第一行包括一个数据组数t(1 <= t <= 100)
接下来每行包括两个正整数a,b(1 <= a, b <= 1000)
输出描述:
输出a+b的结果

示例1
输入
复制
2
1 5
10 20
输出
6
30
*/

#include <iostream>

using namespace std;

int main()
{
    int a, b, t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;

        cout << a + b << endl;
    }

    return 0;
}