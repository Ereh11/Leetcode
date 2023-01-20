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
    ListNode* merge(ListNode* lt1, ListNode* lt2) 
    {         
        if(lt1 == NULL) return lt2;
        if(lt2 == NULL) return lt1;
        
        if(lt1->val < lt2->val)
        {
            lt1->next = merge(lt1->next, lt2);
            return lt1;
        }
        else
        {
            lt2->next = merge(lt1, lt2->next);
            return lt2;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* lt1 = list1, *lt2 = list2;
        return merge(list1,list2);  
    }
};