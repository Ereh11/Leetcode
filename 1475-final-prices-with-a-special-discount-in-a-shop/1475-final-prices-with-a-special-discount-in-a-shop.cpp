class Solution {
public:
    vector<int> finalPrices(vector<int>& v) {
        stack<int> st;  vector<int> ans;
        
        for(int i = v.size() - 1; ~i ; i--)
        {
            while(!st.empty() && v[i] < st.top()) st.pop();
            ans.push_back(st.empty() ? v[i]: v[i] - st.top());
            st.push(v[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};