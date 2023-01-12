class Solution {
public:
    vector<int> edge[201], vis;
    void DFS(int node)
    {
        vis[node] = 1;
        for(auto& child: edge[node])
            if(!vis[child]) DFS(child);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int ans = 0; vis.resize(201);
        for(int i = 0; i < isConnected.size(); i++)
            for(int j = 0; j < isConnected[0].size(); j++)
            {
                if(isConnected[i][j]) edge[i + 1].push_back(j + 1), edge[j + 1].push_back(i+1);
            }
       
        for(int i = 1; i <= isConnected.size(); i++)
            if(!vis[i]) DFS(i), ans++;
        
       return ans;
    }
};