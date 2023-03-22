class Solution {
public:
    void solve(int &n, string ans, set<string> &se)
    {
        if(ans.size() == n)  {
            se.insert(ans);
            return;
        }
        
        for(char ch = 'a'; ch <= 'c' ; ch++) 
        {
            if(ans.empty() || (!ans.empty() && ans.back() != ch))  
            {
                ans.push_back(ch);
                
                solve(n, ans, se);
                
                ans.pop_back();
            }
        }
       
    }
    
    string getHappyString(int n, int k) 
    {
        set<string> se;
        
        solve(n, "", se);
        vector<string> ans = vector(se.begin(), se.end());
        
        return ( (k <= ans.size()) ? ans[k - 1] : "");
    }
};