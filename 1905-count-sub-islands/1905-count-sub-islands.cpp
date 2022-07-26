class Solution {
public:
    int n, m, mark;
    
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    bool b = 1;
    vector<vector<int>> vis;
    bool check(int r, int c) { return(r>=0 && r<n && c>=0 && c<m && vis[r][c]!= mark); }
    
    void BFS(int r, int c, vector<vector<int>>& grid)
    {
        b = 1;
        queue<pair<int, int>> qu; 
        qu.push({r, c}), vis[r][c]= mark;
        while(!qu.empty())
        {
            pair<int, int> ft= qu.front(); qu.pop();
            for(int i=0 ;i < 4; i++)
            {
                int x= dx[i] + ft.first, y= dy[i] + ft.second;
                if(check(x, y) && grid[x][y] == 1) {
                    if(vis[x][y] != 2) b = 0;
                    qu.push({x, y}), vis[x][y] = mark;
                }
            }
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
       int ans = 0;
       mark = 2;
       n= grid2.size(), m= grid2[0].size();
       vis.resize(n, vector<int>(m));
        
       for(int i = 0 ; i < n ;i++)
           for( int j = 0; j< m ; j++) if(vis[i][j] != 2 && grid1[i][j] == 1) BFS(i, j, grid1);
        
       mark = 1;
       for(int i =0 ;i < n ;i++)
           for( int j=0; j< m ; j++) 
               if(vis[i][j] == 2 && grid2[i][j] == 1) {
                   BFS(i, j, grid2);
                   if(b) ans++;
               } 
               
        
      
       
       return ans; 
    }
};