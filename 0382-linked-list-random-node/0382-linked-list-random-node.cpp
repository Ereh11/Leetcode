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
    ListNode* HeadNode;
    
    Solution(ListNode* head) {
       HeadNode = head;
    }
   
    int getRandom() 
    {
        int ans, sz = 1;
        ListNode* nw = HeadNode;
        
        while(nw != nullptr)
        {
            if(rand() % sz == 0) {
                ans = nw->val;
            }
            sz++;
            nw = nw->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */