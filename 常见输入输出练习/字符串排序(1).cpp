/*
链接：https://ac.nowcoder.com/acm/contest/5657/H
来源：牛客网

输入描述:
输入有两行，第一行n

第二行是n个字符串，字符串之间用空格隔开
输出描述:
输出一行排序后的字符串，空格隔开，无结尾空格

输入
5
c d a bb e
输出
a bb c d e
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<string> res;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        res.push_back(tmp);
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << ' ';
    }
    return 0;
}