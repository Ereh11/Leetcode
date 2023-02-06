class Solution {
public:
    int n, m, ans = 0, mx = 0;
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    bool check(int r, int c){ return (r >= 0 && r < n && c >= 0 && c < m);}
    void DFS(int r, int c, vector<vector<int>>& grid)
    {
        ans++, grid[r][c] = 2;
        for(int i = 0 ; i < 4; i++) 
        {
            int x = dx[i] + r, y = dy[i] + c;
            if(check(x, y) && grid[x][y] == 1) DFS(x, y, grid);
        }
        mx = max(mx, ans);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        n = grid.size(), m = grid[0].size();
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++) 
                if(grid[i][j] == 1) ans = 0, DFS(i, j, grid);
        
        return mx;
    }
};