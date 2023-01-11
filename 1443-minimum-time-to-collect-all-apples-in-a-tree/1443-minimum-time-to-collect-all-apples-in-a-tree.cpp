class Solution {
public:
    int DFS(vector<int> adj[], vector<bool> &hasApple, int node, int parent) 
    {
        int distance = 0; 
        for(auto &child: adj[node]) 
        {
            if(child != parent) 
            {
                int temp = DFS(adj, hasApple, child, node);
                if(hasApple[child])
                    distance +=(2 + temp), hasApple[node]=true; 
            } 
        }
        return distance;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(int i=0; i < edges.size(); i++) 
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return DFS(adj, hasApple, 0, 0);
    }
};