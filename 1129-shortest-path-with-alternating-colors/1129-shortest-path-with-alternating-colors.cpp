class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
            vector<vector<pair<int, int>>> edge(n);
            for (auto& it : redEdges) 
                edge[it[0]].push_back({it[1], 0});
        
            for (auto& it : blueEdges) 
                edge[it[0]].push_back(make_pair(it[1], 1));
        
            vector<vector<int>> vis(n, vector<int>(2));
            vector<int> ans(n, -1);
            queue<vector<int>> q;

       
        
            q.push({0, 0, -1});
            vis[0][1] = vis[0][0] = 1, ans[0] = 0;

            while (!q.empty()) 
            {
                auto ft = q.front();
                int node = ft[0], steps = ft[1], c = ft[2];
                q.pop();

                for (auto& [neighbor, color] : edge[node]) 
                {
                    if (!vis[neighbor][color] && color != c) 
                    {
                        vis[neighbor][color] = true;
                        q.push({neighbor, 1 + steps, color});
                        if (ans[neighbor] == -1) 
                            ans[neighbor] = 1 + steps;
                    }
               }
           }
        
          return ans;
    }
};