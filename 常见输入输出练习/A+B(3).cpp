/*
���ӣ�https://ac.nowcoder.com/acm/contest/5657/C
��Դ��ţ����

��������:
�����������������a,b(1 <= a, b <= 10^9),���������ж���, �������Ϊ0 0���������
�������:
���a+b�Ľ��

ʾ��1
����
1 5
10 20
0 0
���
6
30
*/

#include <iostream>

using namespace std;

int main()
{
    int a, b, n;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
            return 0;
        cout << a + b << endl;
    }
    return 0;
}