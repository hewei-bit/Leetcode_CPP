/*
链接：https://ac.nowcoder.com/acm/contest/5657/G
来源：牛客网

输入描述:
输入数据有多组, 每行表示一组输入数据。

每行不定有n个整数，空格隔开。(1 <= n <= 100)。
输出描述:
每组数据输出求和的结果

示例1
输入
1 2 3
4 5
0 0 0 0 0
输出
6
9
0
*/

#include <iostream>
using namespace std;
int main()
{
    int n;
    int res = 0;
    while (cin >> n)
    {
        res += n;
        if (cin.get() == '\n')
        {
            cout << res << endl;
            res = 0;
        }
    }
    return 0;
}