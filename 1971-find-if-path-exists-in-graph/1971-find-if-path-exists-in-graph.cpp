class Solution {
public:
    const static int N = 2 * 1e5 + 1;
    vector<int> vis;
    vector<int> edge[N];
    bool b = 0;
    void DFS(int node, int &destination)
    {
        vis[node] = 1;
        if(node == destination) b = 1;
        
        for(auto& it: edge[node])
            if(!vis[it]) DFS(it, destination);   
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vis.resize(n);
        for(auto &r: edges) 
            edge[r[0]].push_back(r[1]), edge[r[1]].push_back(r[0]);
        DFS(source, destination);
        return b;
    }
};