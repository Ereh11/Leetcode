class Solution {
public:
    int dx[4] = {1, -1, 0 , 0};
    int dy[4] = {0, 0, 1, -1};
    int n, m;
    bool check(int r, int c) { return(r >= 0 && r < n && c >= 0 && c < m); }
  
    void DFS(int r, int c, vector<vector<int>>& grid)
    {
        grid[r][c] = 2;
        for(int k = 0 ; k < 4 ; k++) {
            int x = dx[k] + r, y = dy[k] + c;
            if(check(x, y) && grid[x][y] == 1) DFS(x, y, grid);
        }
    }
    
    
    int BFS(queue<pair<int, int>> &qu, vector<vector<int>>& grid)
    {
        int dist = 0;
        
        while(!qu.empty())
        {
            int sz = qu.size();
            while(sz--)
            {
                auto ft = qu.front(); qu.pop();
                for(int k = 0 ; k < 4 ; k++)
                {
                    int x = dx[k] + ft.first, y = dy[k] + ft.second;
                    if(check(x, y))
                    {
                        if(grid[x][y] == 2) return dist;
                        if(grid[x][y] == 0) qu.push({x, y}), grid[x][y] = 1;
                    }
                }
            }
            dist++;
        }
        
        return dist;
    }
    
    
    
    int shortestBridge(vector<vector<int>>& grid) 
    {
        n = grid.size(), m = grid[0].size(); 
        queue<pair<int, int>> qu;
       
        bool b = 1;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m && b; j++) 
                if(grid[i][j] == 1) DFS(i, j, grid), b = 0;
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(grid[i][j] == 1) qu.push({i, j});
            
       
        return BFS(qu, grid);
    }
};