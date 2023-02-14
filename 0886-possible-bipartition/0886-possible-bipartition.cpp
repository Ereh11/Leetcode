class Solution {
public:
    static const int N = 1e4 + 1;
    vector<int> edge[N];
    vector<int> color;
    bool ans = 1;
    void DFS(int node)
    {
        for(auto& child: edge[node])
            if(!color[child]) color[child] = 2 - color[node], DFS(child);
            else if(color[child] == color[node]){ ans = 0; return; }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        color.resize(n + 1);
        
        for(auto& r: dislikes) 
            edge[r[0]].push_back(r[1]), edge[r[1]].push_back(r[0]);
        
        for(int i = 1; ans && i <= n ; i++)
            if(!color[i]) DFS(i);
        
        
        return ans;
    }
  
};