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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>v;
     TreeNode* solve(int l,int r)
     {
       if(l>r) return NULL;

       int mid = ((l + r) >> 1);
       TreeNode* ans=new TreeNode(v[mid]);
         
       ans->left = solve(l, mid - 1);
       ans->right = solve(mid + 1, r);
       return ans;
     }
    
    TreeNode* sortedListToBST(ListNode* head) {
       
      while(head != NULL)
      {
        v.push_back(head->val);
        head=head->next;
      }
      
      return solve(0, v.size() - 1);
      
    }
};