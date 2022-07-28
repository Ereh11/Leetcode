class Solution {
public:
    int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
    int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
    int n, m;
    vector<vector<int>> vis;
    bool check(int r, int c) { return(r>=0 && r<n && c>=0 && c<m && !vis[r][c]); }
    
    void BFS(vector<vector<int>>& grid)
    {
        if(grid[0][0]) return;
        
        queue<pair<int, int>> qu; 
        qu.push({0, 0}); vis[0][0] = 1;
        
        while(!qu.empty())
        {
            pair<int, int> ft= qu.front(); qu.pop();
            if(ft.first == n - 1 && ft.second == m - 1) return;
            for(int i = 0 ; i < 8 ; i++)
            {
                int x = dx[i] + ft.first, y = dy[i] + ft.second;
                if(check(x, y) && !grid[x][y])
                   qu.push({x, y}), vis[x][y] = vis[ft.first][ft.second] + 1;
            }
        }
        
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vis.resize(n, vector<int>(m));
        BFS(grid);
        return (( vis[n - 1][m - 1]) ? vis[n - 1][m - 1] : -1 );
    }
};