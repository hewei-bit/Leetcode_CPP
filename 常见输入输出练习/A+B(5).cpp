/*
���ӣ�https://ac.nowcoder.com/acm/contest/5657/E
��Դ��ţ����

��������:
����ĵ�һ�а���һ��������t(1 <= t <= 100), ��ʾ����������
������t��, ÿ��һ�����ݡ�
ÿ�еĵ�һ������Ϊ�����ĸ���n(1 <= n <= 100)��
������n��������, ����Ҫ��͵�ÿ����������
�������:
ÿ�����������͵Ľ��
ʾ��1
����
2
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
    int a, b;
    while (cin >> a && a != 0)
    {
        for (int i = 0; i < a; i++)
        {
            cin >> b;
            int sum = 0;
            for (int j = 0; j < b; j++)
            {
                int c;
                cin >> c;
                sum += c;
            }
            cout << sum << endl;
        }
    }
    return 0;
}