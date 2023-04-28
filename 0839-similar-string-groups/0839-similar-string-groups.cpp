class Solution {
public:
    bool similar(string &s, string &t)
    {
        int dif=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=t[i]){
                dif++;
            }
        }
        
        return dif <= 2;
    }
    
    void dfs(int node, vector<int> &vis, vector<vector<int>> &graph){
        
        vis[node] = 1;
        
        for(auto&child:graph[node])
        {
            if(!vis[child]){
                dfs(child,vis,graph);
            }
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int sz = strs.size();
        vector<vector<int>>graph(sz);
        for(int i = 1; i < sz; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(similar(strs[i], strs[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<int>vis(sz);
        
        for(int i = 0; i < sz; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, graph);
                ans++;
            }
        }
        return ans;
    }
};