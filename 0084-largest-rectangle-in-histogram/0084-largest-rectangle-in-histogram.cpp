class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        long long ans = 0, ht = 0;
        stack<long long> st; heights.push_back(0);
        
        for(int i = 0 ; i < heights.size() ; i++) 
        {    
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                ht = heights[st.top()];   st.pop();
                if(st.empty()) ans = max(ans, ht * i);
                else ans = max(ans, ht * (i - st.top() - 1));
            }
            st.push(i);
        }
        
        return ans;
    }
};