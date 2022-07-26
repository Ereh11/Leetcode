class Solution {
public:
    int n, m;
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    bool b = 1;
    vector<vector<bool>> vis;
    bool check(int r, int c) { return(r>=0 && r<n && c>=0 && c<m && !vis[r][c]); }
    int BFS(int r, int c, vector<vector<int>>& grid)
    {
        b = 1; 
        int cnt = 0;
        queue<pair<int, int>> qu; 
        qu.push({r, c}), vis[r][c]= 1;
        while(!qu.empty())
        {
            pair<int, int> ft= qu.front(); 
            qu.pop(), cnt++;
            
            if(!ft.first|| ft.first== n-1 || !ft.second || ft.second == m-1) b= 0;
            
            for(int i=0 ;i < 4; i++)
            {
                int x= dx[i] + ft.first, y= dy[i] + ft.second;
                if(check(x, y) && grid[x][y]) 
                    qu.push({x, y}), vis[x][y] = 1;
            }
        }
        return cnt;
    }
    int numEnclaves(vector<vector<int>>& grid) {
       int ans= 0;
       n= grid.size(), m= grid[0].size();
       vis.resize(n, vector<bool>(m));
        
       for(int i =0 ;i < n ;i++)
           for( int j=0; j< m ; j++) 
               if(!vis[i][j] && grid[i][j]){
                   int cnt = BFS(i, j, grid);
                   ans+= ((b)? cnt : 0);
               }
        
       return ans;
    }
};