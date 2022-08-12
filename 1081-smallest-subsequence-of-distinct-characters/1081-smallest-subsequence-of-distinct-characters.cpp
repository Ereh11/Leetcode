class Solution {
public:
    string smallestSubsequence(string s) {
        string ans;
        
	    vector<int> frq(26), ext(26);
	    stack<char> st;
        
	    for (auto& it : s) frq[it - 97]++;
	
	    for (auto& it : s)
	    {
		    while (!ext[it - 97] && !st.empty() && frq[st.top() - 97] && st.top() > it)
			    ext[st.top() - 97] = 0, st.pop();

		    if (!ext[it - 97]) st.push(it), ext[it - 97] = 1;
		    frq[it - 97]--;
	    }
        
	    while (!st.empty()) ans += st.top(), st.pop();
	    reverse(ans.begin(), ans.end());
        
	    return ans;
    }
};