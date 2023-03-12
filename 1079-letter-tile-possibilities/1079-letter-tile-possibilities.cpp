class Solution {
public:
    unordered_set<string> se;
    bool vis[8];
    
    void solve(string &tiles, string ans)
    {
        for(int i = 0 ; i < tiles.size() ; i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                ans.push_back(tiles[i]);
                
                if(se.find(ans) == se.end())  se.insert(ans);
                
                solve(tiles, ans);
                vis[i] = 0;
                ans.pop_back();
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        
        solve(tiles, "");
        return se.size();
    }
};