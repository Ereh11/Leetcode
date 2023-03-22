class Solution {
public:
    void solve(string &required, int &n, string ans, set<string> &se)
    {
        if(ans.size() == n)  {
            se.insert(ans);
            return;
        }
        
        for(int i = 0; i < 3 ; i++) 
        {
            if(ans.empty() || (!ans.empty() && ans.back() != required[i]))  
            {
                ans.push_back(required[i]);
                
                solve(required, n, ans, se);
                
                ans.pop_back();
            }
        }
       
    }
    
    string getHappyString(int n, int k) 
    {
        set<string> se;
        string required = "abc";
        
        solve(required, n, "", se);
        vector<string> ans = vector(se.begin(), se.end());
        
        return ( (k <= ans.size()) ? ans[k - 1] : "");
    }
};