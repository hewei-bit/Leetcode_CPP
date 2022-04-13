/**
 * @File Name: 20 ��ʾ��ֵ���ַ���.cpp
 * @Brief :
 * @Author : hewei (hewei_1996@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-13
 *
 */
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution
{
private:
    // �����ĸ�ʽ������[+|-]B��ʾ, ����BΪ�޷�������
    bool scanInteger(const string s, int &index)
    {

        if (s[index] == '+' || s[index] == '-')
            ++index;

        return scanUnsignedInteger(s, index);
    }

    bool scanUnsignedInteger(const string s, int &index)
    {

        int befor = index;
        while (index != s.size() && s[index] >= '0' && s[index] <= '9')
            index++;

        return index > befor;
    }

public:
    // ���ֵĸ�ʽ������A[.[B]][e|EC]����.B[e|EC]��ʾ��
    // ����A��C���������������������ţ�Ҳ����û�У�����B��һ���޷�������
    bool isNumber(string s)
    {

        if (s.size() == 0)
            return false;
        int index = 0;

        //�ַ�����ʼ�пո񣬿��Է���true
        while (s[index] == ' ') //���д���û�и������
            ++index;

        bool numeric = scanInteger(s, index);

        // �������'.'�������������ֵ�С������
        if (s[index] == '.')
        {

            ++index;

            // ����һ�д�����||��ԭ��
            // 1. С������û���������֣�����.123����0.123��
            // 2. С����������û�����֣�����233.����233.0��
            // 3. ��ȻС����ǰ��ͺ�����������֣�����233.666
            numeric = scanUnsignedInteger(s, index) || numeric;
        }

        // �������'e'����'E'�����������ŵ������ֵ�ָ������
        if (s[index] == 'e' || s[index] == 'E')
        {

            ++index;

            // ����һ�д�����&&��ԭ��
            // 1. ��e��Eǰ��û������ʱ�������ַ������ܱ�ʾ���֣�����.e1��e1��
            // 2. ��e��E����û������ʱ�������ַ������ܱ�ʾ���֣�����12e��12e+5.4
            numeric = numeric && scanInteger(s, index);
        }

        //�ַ�����β�пո񣬿��Է���true
        while (s[index] == ' ')
            ++index;
        cout << s.size() << " " << index; //������

        return numeric && index == s.size();
    }
};