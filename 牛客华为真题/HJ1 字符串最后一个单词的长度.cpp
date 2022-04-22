#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    // int length = s.length();
    // int tmp = -1;
    // for (int i = 0; i < length; i++)
    // {
    //     if (s[i] == ' ')
    //         tmp = i;
    // }
    // cout << length - tmp - 1 << endl;
    // return 0;

    int i = s.size() - 1;
    for (string::reverse_iterator ptr1 = s.rbegin(); ptr1 != s.rend(); ++ptr1)
    {
        if (*ptr1 == ' ')
            break;
        i--;
    }
    cout << s.size() - 1 - i << endl;
}