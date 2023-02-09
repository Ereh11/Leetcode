class Solution {
public:
    queue<pair<int, int>> qu;
    int n, m, ans = 0;
    int dx[4] = {1, -1, 0 , 0};
    int dy[4] = {0 , 0 , 1, -1};
    bool check(int r, int c) { return (r < n && r >= 0 && c < m && c >= 0);}
    int BFS(vector<vector<int>>& grid)
    {
        map<pair<int, int>, int> vis;
        while(!qu.empty())
        {
            int sz = qu.size();
            while(sz--)
            {
                auto ft = qu.front(); qu.pop(); 
                for(int i = 0; i < 4 ;i++) 
                {
                    int x = ft.first + dx[i], y = ft.second + dy[i];
                    if(check(x, y) && !vis[{x, y}] && !grid[x][y])
                        vis[{x, y}] = 1, qu.push({x, y});
                }
            }
            ans++;
        }
        
        return ans;
    }
    
    
    
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(grid[i][j]) qu.push({i, j});
        
        BFS(grid);        
        return (ans == 1 ? -1 : ans - 1);
    }
};