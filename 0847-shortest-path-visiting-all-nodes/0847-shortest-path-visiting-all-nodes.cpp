class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool> (1<<n, false));
        
        for(int i=0; i<n; i++) {
            q.push({i, 1<<i});
            vis[i][1<<i] = 1;
        }
        int ans = 0;
        while(q.size()) {
            for(int k = q.size(); k; k--) {
                auto [i, mask] = q.front();
                q.pop();
                if(mask == (1<<n)-1) return ans;
                for(auto x: graph[i]) {
                    if(!vis[x][mask | (1 << x)]) {
                        q.push({x, mask | (1 << x)});
                        vis[x][mask | (1 << x)] = 1;
                    }
                }
            }
            ans++;
        }
        return ans;   
    }
    
};