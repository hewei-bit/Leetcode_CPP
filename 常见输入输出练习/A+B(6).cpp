/*
���ӣ�https://ac.nowcoder.com/acm/contest/5657/F
��Դ��ţ����

��������:
���������ж���, ÿ�б�ʾһ���������ݡ�
ÿ�еĵ�һ������Ϊ�����ĸ���n(1 <= n <= 100)��
������n��������, ����Ҫ��͵�ÿ����������
�������:
ÿ�����������͵Ľ��

ʾ��1
����
4 1 2 3 4
5 1 2 3 4 5
���
10
15
*/

#include <iostream>
using namespace std;
int main()
{
    int a;
    while (cin >> a)
    {
        int b;
        int sum = 0;
        while (a--)
        {
            cin >> b;
            sum += b;
        }
        cout << sum << endl;
    }
    return 0;
}