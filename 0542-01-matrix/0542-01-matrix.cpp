class Solution {
public:
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    
    int n, m;
    vector<vector<int>> dist;
    queue<pair<int, int>> qu;
    bool check(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < m); }
    
    void BFS()
    {
        while(!qu.empty())
        {
            auto ft = qu.front(); qu.pop();
            for(int i = 0 ; i < 4 ; i++) 
            {
                int x = ft.first + dx[i], y = ft.second + dy[i];
                if(check(x, y) && dist[x][y] > dist[ft.first][ft.second] + 1)
                {
                    dist[x][y] = dist[ft.first][ft.second] + 1;
                    qu.push({x, y});
                }
            }
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        dist.resize(n, vector<int>(m, INT_MAX));
        
        for(int i = 0; i < n ;i++)
            for(int j = 0; j < m ;j++)
            {
                if(!mat[i][j])
                    qu.push({i, j}),  dist[i][j] = 0;
            }
        
        BFS();
        return dist;
    }
};
