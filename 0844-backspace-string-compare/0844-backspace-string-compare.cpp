class Solution {
public:
    
    void solve(string &s, stack<char> &st)
    {
        for(auto& it: s)
            if(it == '#' && !st.empty()) st.pop();
            else if(it != '#') st.push(it);
    }
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        solve(s, st1); solve(t, st2);
        
        if(st1.size() != st2.size()) return false;
        
        while(!st1.empty() && !st2.empty()) 
            if(st1.top() != st2.top()) return false;
            else st1.pop(), st2.pop();
        
        return true;
    }
};