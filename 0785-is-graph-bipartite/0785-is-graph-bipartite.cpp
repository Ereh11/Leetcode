class Solution {
public:
    vector<int> edge[101], color; bool ans = 1;
    void DFS(int node)
    {
        for(auto& child: edge[node])
        {
            if(!color[child]) 
                color[child] = 3 - color[node], DFS(child);
            else if(color[child] == color[node]) ans = 0;
        }
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        color.resize(graph.size());
        
        for(int i = 0 ; i < graph.size(); i++)
            for(int j = 0 ; j < graph[i].size(); j++) 
                edge[i].push_back(graph[i][j]), edge[graph[i][j]].push_back(i);
        
        for(int i = 0 ; i < graph.size(); i++)
            if(!color[i]) color[i] = 2, DFS(i);
        
        return ans;
    }
};