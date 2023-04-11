class Solution {
public:
    string removeStars(string s) {
        
        stack<char> st;
        string ans;
        
        for(auto& it: s)
        {
            if(st.empty())   st.push(it);
            else
            {
                if(it == '*')
                    st.pop();
                else
                    st.push(it);
            }
        }
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();         
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};