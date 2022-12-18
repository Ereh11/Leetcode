class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        vector<int> ans;
        stack<pair<int, int>> st; st.push({-1, v.size() - 1});
        
        for(int i = v.size() - 1 ; ~i ; i--)
        {
            while(!st.empty() && v[i] >= st.top().first) st.pop();
            
            ans.push_back(((st.empty() ? 0 : st.top().second - i))), st.push({v[i], i});
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};