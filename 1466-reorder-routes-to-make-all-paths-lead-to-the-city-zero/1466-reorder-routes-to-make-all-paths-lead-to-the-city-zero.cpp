class Solution {
public:
    int ans = 0;
    void DFS(int node, int parent, vector<vector<pair<int, int>>>& edge) 
    {
        for (auto& [child, sign] : edge[node]) 
            if (child != parent) 
            {
                ans += sign;
                DFS(child, node, edge);
            }
        
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> edge(n);
        for (auto& connection : connections) 
        {
            edge[connection[0]].push_back({connection[1], 1});
            edge[connection[1]].push_back({connection[0], 0});
        }
        
        DFS(0, -1, edge);
        return ans;
    }
};