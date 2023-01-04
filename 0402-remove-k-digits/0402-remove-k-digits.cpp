class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char> st;
        string ans, tp;
        if(k && s.size() > 1)
        {
            for(auto& it: s) {
                 while(!st.empty() && st.top() > it && k) st.pop(), k--;
                 st.push(it);
            }
        }
        
        while(k && !st.empty()) st.pop(), k--;
        while(!st.empty()) tp.push_back(st.top()), st.pop();
        
        reverse(tp.begin(), tp.end());
        for(auto& it: tp){
            if(it == '0' && ans.empty()) continue;
            ans.push_back(it);
        } 
        
        return (ans.empty() ? "0" : ans);
    }
};