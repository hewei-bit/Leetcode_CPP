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
