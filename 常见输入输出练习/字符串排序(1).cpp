/*
���ӣ�https://ac.nowcoder.com/acm/contest/5657/H
��Դ��ţ����

��������:
���������У���һ��n

�ڶ�����n���ַ������ַ���֮���ÿո����
�������:
���һ���������ַ������ո�������޽�β�ո�

����
5
c d a bb e
���
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