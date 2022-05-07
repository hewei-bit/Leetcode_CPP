/**
 * @File Name: 28 й╣ож strStr().cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-07
 *
 */

#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
#if 1
    int strStr(string haystack, string needle)
    {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i + m <= n; i++)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return i;
        }
    }
#elif 1
    int strStr(string haystack, string needle)
    {
        }
#else

#endif
};