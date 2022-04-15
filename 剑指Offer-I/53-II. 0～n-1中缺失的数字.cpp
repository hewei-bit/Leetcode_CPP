/**
 * @File Name: 53-II. 0¡«n-1ÖÐÈ±Ê§µÄÊý×Ö.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-15
 *
 */
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        //
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == mid)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return l;
    }
};