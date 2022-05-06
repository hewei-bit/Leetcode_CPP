/*
链接：https://ac.nowcoder.com/acm/contest/5657/J
来源：牛客网

输入描述:
多个测试用例，每个测试用例一行。
每行通过,隔开，有n个字符，n＜100
输出描述:
对于每组用例输出一行排序后的字符串，用','隔开，无结尾空格

示例1
输入
a,c,bb
f,dddd
nowcoder

输出
a,bb,c
dddd,f
nowcoder
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    string lines;
    while (cin >> lines)
    {
        string sub;
        vector<string> vec;
        stringstream ss(lines);
        while (getline(ss, sub, ','))
        {
            vec.push_back(sub);
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size(); i++)
        {
            if (i != vec.size() - 1)
                cout << vec[i] << ',';
            else
                cout << vec[i] << endl;
        }
        vec.clear();
    }

    return 0;
}