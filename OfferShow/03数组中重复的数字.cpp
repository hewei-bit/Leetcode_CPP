// �ҳ��������ظ������֡�

// ��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�
// ������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ�
// ���ҳ�����������һ���ظ������֡�

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        unordered_map<int, bool> res;
        for (int num : nums)
        {
            if (res[num])
                return num;
            res[num] = true;
        }
        return -1;
    }
};