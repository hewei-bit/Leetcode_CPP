/*
���ӣ�https://ac.nowcoder.com/acm/contest/5657/D
��Դ��ţ����

��������:
�������ݰ������顣
ÿ������һ��,ÿ�еĵ�һ������Ϊ�����ĸ���n(1 <= n <= 100), nΪ0��ʱ��������롣
������n��������,����Ҫ��͵�ÿ����������
�������:
ÿ�����������͵Ľ��
ʾ��1
����
4 1 2 3 4
5 1 2 3 4 5
0
���
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