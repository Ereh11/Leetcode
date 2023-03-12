class Solution {
public:
    bool vis[10];
    set<string> se;
    
    void solve(string &pattern, int indx, string ans)
    {
        if(ans.size() == pattern.size() + 1)
            se.insert(ans);
        
        if(!indx)
        {
            for(int i = 1 ; i <= 9 ; i++)
            {
                if(!vis[i])
                {
                    vis[i] = 1;
                    ans.push_back(i + 48);
                    
                    solve(pattern, indx + 1, ans);
                    
                    ans.pop_back();
                    vis[i] = 0;
                }
            }
        }
        
        else if(pattern[indx - 1] == 'I')
        {
            for(int i = 1 ; i <= 9 ; i++)
            {
                 if(!vis[i] && i > int(ans.back()) - 48)
                {
                    vis[i] = 1;
                    ans.push_back(i + 48);
                     
                    solve(pattern, indx + 1, ans);
                     
                    ans.pop_back();
                    vis[i] = 0;
                }
            }
        }
        
        else
        {
            for(int i = 1 ; i <= 9 ; i++)
            {
                 if(!vis[i] && i < int(ans.back()) - 48)
                {
                    vis[i] = 1;
                    ans.push_back(i + 48);
                     
                    solve(pattern, indx + 1, ans);
                     
                    ans.pop_back();
                    vis[i] = 0;
                }
            }
        }
    }
    
    
    string smallestNumber(string pattern) {
        solve(pattern, 0, "");
        return *se.begin();
    }
};