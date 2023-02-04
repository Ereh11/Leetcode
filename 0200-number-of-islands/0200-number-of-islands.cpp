class Solution {
public:
    int n, m;
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    vector<vector<bool>> vis;
    bool check(int r, int c) { return(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c]); }
    void DFS(int r, int c, vector<vector<char>>& grid)
    {
        vis[r][c] = 1;
        for(int i = 0 ;i < 4; i++)
        {
            int x= dx[i] + r, y= dy[i] + c;
            if(check(x, y) && grid[x][y] == '1') DFS(x, y, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
       int ans= 0;
       n= grid.size(), m= grid[0].size();
       vis.resize(n, vector<bool>(m));
        
       for(int i =0 ;i < n ;i++)
           for( int j=0; j< m ; j++) 
               if(!vis[i][j] && grid[i][j] == '1') ans++, DFS(i, j, grid);
        
       return ans; 
    }
};