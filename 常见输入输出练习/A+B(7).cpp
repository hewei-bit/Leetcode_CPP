/*
���ӣ�https://ac.nowcoder.com/acm/contest/5657/G
��Դ��ţ����

��������:
���������ж���, ÿ�б�ʾһ���������ݡ�

ÿ�в�����n���������ո������(1 <= n <= 100)��
�������:
ÿ�����������͵Ľ��

ʾ��1
����
1 2 3
4 5
0 0 0 0 0
���
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