/**
 * @File Name: 53-I. �����������в������� I.cpp
 * @Brief : ���ֲ���
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
    //�������ζ��ַ��ֱ�ȷ��target�����ұ߽磨���ұ߽�Ϊtargetֵ���е���/��һλ��������ս����right-left-1��
    int search(vector<int> &nums, int target)
    {

        if (nums.size() == 0)
        {
            return 0;
        }
        //
        int left = 0;
        int right = nums.size() - 1;

        //��һ�ζ��֣���right�߽�

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            //�����ǡ�С�ڵ��ڡ���Ŀ����Ϊ��ȷ���ұ߽磬
            // ����˵��mid����targetʱ����Ϊ��ȷ�����滹��û��target��
            // ����ͬ����Ҫ���������Χ
            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
        }

        if (right >= 0 && nums[right] != target)
        {
            return 0;
        }

        int right_edge = left;

        // ����
        left = 0;
        right = nums.size() - 1;
        //�ڶ��ζ��֣���left�߽�

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            //�����ǡ����ڵ��ڡ���Ŀ����ȷ����߽磬
            //  ��Ϊ���㵱mid����target��ʱ����Ϊ��ȷ����߻���û��target��
            // ����ͬ����Ҫ�����ұ߽�
            if (nums[mid] >= target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        int left_edge = right;

        return right_edge - left_edge - 1;
    }
};