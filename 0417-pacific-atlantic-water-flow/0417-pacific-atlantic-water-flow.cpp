class Solution {
public:
    int m,n;
    int dx [4] = {1, -1, 0 , 0};
    int dy [4] = {0, 0, 1 , -1};
    queue<pair<int,int>> pac;
    queue<pair<int,int>> atl;
    
    bool valid(int x, int y){  return x >= 0 && x < m && y >= 0 && y < n;  }
    
    
    void BFS(queue<pair<int,int>> &qu, vector<vector<int>> &vis, vector<vector<int>>& matrix)
    {
        while(!qu.empty())
        {
            auto ft = qu.front();
            qu.pop();
            vis[ft.first][ft.second] = 1;
           
            for(int i = 0; i < 4; i++)
            {
                int x = ft.first + dx[i], y = ft.second + dy[i]; 
                if(valid(x, y) && matrix[ft.first][ft.second] <= matrix[x][y] && !vis[x][y])
                    qu.push({x, y});
            }
        }
    }
    
        
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> ans;
        m = matrix.size(), n = matrix[0].size();
 
        vector<vector<int>> visp(m, vector<int>(n,0));
        vector<vector<int>> visq(m, vector<int>(n,0));
        
        for(int i = m - 1; i >= 0; i--) pac.push({i,0});
        for(int i = n - 1; i >= 0; i--) pac.push({0,i});
    
        for(int i = m - 1; i >= 0; i--) atl.push({i,n-1});
        for(int i = n - 1; i >= 0; i--) atl.push({m-1,i});
        
        BFS(pac, visp, matrix);
        BFS(atl, visq, matrix);
        
        for(int i = 0; i < m ;i++)
            for(int j = 0; j < n ;j++)
                if(visp[i][j] && visq[i][j]) ans.push_back({i,j});
            
        return ans;
    }
};