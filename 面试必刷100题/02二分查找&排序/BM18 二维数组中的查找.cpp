/**
 * @File Name: BM18 二维数组中的查找.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-05-11
 *
 */

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool Find(int target, vector<vector<int>> array)
    {
        int i = array.size() - 1;
        int j = 0;
        while (j < array[0].size() && i > 0)
        {
            if (target < array[i][j])
                i--;
            else if (target > array[i][j])
                j++;
            else
                return true;
        }
        return false;
    }
};