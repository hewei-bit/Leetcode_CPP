/*
���ӣ�https://ac.nowcoder.com/acm/contest/5657/I
��Դ��ţ����

��������:
�������������ÿ����������һ�С�

ÿ��ͨ���ո��������n���ַ���n��100
�������:
����ÿ��������������һ����������ַ�����ÿ���ַ���ͨ���ո����
ʾ��1
����
a c bb
f dddd
nowcoder

���
a bb c
dddd f
nowcoder
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<string> res;
    string s;

    while (cin >> s)
    {
        res.push_back(s);
        if (cin.get() == '\n')
        {
            sort(res.begin(), res.end());
            for (string temp : res)
            {
                cout << temp << " ";
            }
            cout << endl;
            res.clear();
        }
    }

    return 0;
}