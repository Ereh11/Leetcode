class Solution {
public:
    bool vis[10];
    set<string> se;
    void Calculate(int &i, string &pattern, int &indx, string &ans)
    {
        if(!vis[i]) {
            vis[i] = 1;
            ans.push_back(i + 48);

            solve(pattern, indx + 1, ans);

            ans.pop_back();
            vis[i] = 0;
        }
    }
    
    void solve(string &pattern, int indx, string ans)
    {
        if(ans.size() == pattern.size() + 1)
            se.insert(ans);
        
        if(!indx)
        {
            for(int i = 1 ; i <= 9 ; i++)
                Calculate(i, pattern, indx, ans);
        }
        
        else if(pattern[indx - 1] == 'I')
        {
            for(int i = 1 ; i <= 9 ; i++) {
                 if(i > int(ans.back()) - 48)
                     Calculate(i, pattern, indx, ans);
            }
        }
        
        else
        {
            for(int i = 1 ; i <= 9 ; i++) {
                 if(i < int(ans.back()) - 48)
                    Calculate(i, pattern, indx, ans);
            }
        }
    }
    
    
    string smallestNumber(string pattern) {
        solve(pattern, 0, "");
        return *se.begin();
    }
};