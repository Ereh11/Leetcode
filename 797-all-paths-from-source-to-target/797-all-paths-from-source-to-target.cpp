class Solution {
public:
    vector<int> edge[16];
    int n;
    vector<vector<int>> ans;
    vector<int> path;
    void DFS(int node,vector<vector<int>>& graph)
    {
        if(node == n - 1) { ans.push_back(path); return; }
        for(auto& child: edge[node])
        {
            path.push_back(child);
            DFS(child, graph);
            path.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        
        for(int i = 0 ; i < n; i++)
            for(int j = 0 ; j < graph[i].size() ; j++)
                edge[i].push_back(graph[i][j]);
        
        path.push_back(0);
        DFS(0, graph);
        return ans;
    }
};