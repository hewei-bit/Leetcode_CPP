#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//!!!�����ִ�Сд�����Խ���ascll��+32һ��Ҳ++
int main()
{
    string str;
    char s;
    int count = 0;
    getline(cin, str);
    cin >> s;
    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if (str[i] == s || str[i] + 32 == s || str[i] - 32 == s)
            {
                count++;
            }
        }
        if ((str[i] >= '0' && str[i] <= '9'))
        {
            if (str[i] == s)
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
