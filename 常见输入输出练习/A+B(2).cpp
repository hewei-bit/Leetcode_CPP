/*
���ӣ�https://ac.nowcoder.com/acm/contest/5657/B
��Դ��ţ����

��������:
�����һ�а���һ����������t(1 <= t <= 100)
������ÿ�а�������������a,b(1 <= a, b <= 1000)
�������:
���a+b�Ľ��

ʾ��1
����
����
2
1 5
10 20
���
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