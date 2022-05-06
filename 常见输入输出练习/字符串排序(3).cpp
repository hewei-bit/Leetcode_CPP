/*
���ӣ�https://ac.nowcoder.com/acm/contest/5657/J
��Դ��ţ����

��������:
�������������ÿ����������һ�С�
ÿ��ͨ��,��������n���ַ���n��100
�������:
����ÿ���������һ���������ַ�������','�������޽�β�ո�

ʾ��1
����
a,c,bb
f,dddd
nowcoder

���
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