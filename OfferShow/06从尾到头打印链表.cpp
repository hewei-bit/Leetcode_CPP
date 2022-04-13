#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        stack<int> helper;
        vector<int> res;
        ListNode *temp = head;
        while (temp != NULL)
        {
            helper.push(temp->val);
            temp = temp->next;
        }

        while (!helper.empty())
        {
            res.push_back(helper.top());
            helper.pop();
        }
        return res;
    }
};