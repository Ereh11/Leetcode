/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) 
    {
        string ans;
        
        while(head != nullptr)
           ans.push_back(((head->val) ? '1' : '0')), head = head->next;
        
        return bitset<32>(ans).to_ulong();
    }
};