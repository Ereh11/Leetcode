class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ans;
        stack<int> st; st.push(-1);
        
        for(int i = nums2.size() - 1 ; ~i ; i--)
        {
            while(~st.top() && nums2[i] > st.top()) st.pop();
            ans[nums2[i]] = st.top(), st.push(nums2[i]);
        }
        
        for(auto& it: nums1) it = ans[it];
        
        return nums1;
    }
};