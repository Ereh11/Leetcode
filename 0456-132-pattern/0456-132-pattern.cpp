class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        stack<int> st; 
        int mx = INT_MIN;
        for(int i = nums.size() - 1; ~i; i--)
        {
            if(nums[i] < mx) return true;
            else
            {
                while(!st.empty() && nums[i] > st.top())
                    mx = st.top(), st.pop();
            }
                
            st.push(nums[i]);
        }
        
        return false;      
    }
};