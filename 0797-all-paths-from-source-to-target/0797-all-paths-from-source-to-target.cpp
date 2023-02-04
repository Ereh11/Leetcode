class Solution {
public:
    vector<int> edge[15], path;
    vector<vector<int>> ans;
    void DFS(int node, int &n)
    {
        if(node == n - 1) {ans.push_back(path); return; }
        for(auto& child: edge[node])
        {
            path.push_back(child);
            DFS(child, n);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        for(int i = 0 ; i < n ;i++)
            for(int j = 0 ; j < graph[i].size() ;j++)
                edge[i].push_back(graph[i][j]);
        path.push_back(0);
        DFS(0, n);
        return ans;
    }
};

/*
*/