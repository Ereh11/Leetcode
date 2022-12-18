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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cu = head;
        while(cu != nullptr && cu->next!= nullptr)
            if(cu->val == cu->next->val) cu->next = cu->next->next;
            else cu = cu->next;
            
        return head;
    }
};