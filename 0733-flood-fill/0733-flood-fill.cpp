class Solution {
public:
    bool valid(int r, int c, int n, int m){ return (r >= 0 && r < n && c >= 0 && c < m); }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        queue<pair<int, int>> qu;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        qu.push({sr, sc});
        int n = image.size(), m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
            
        while(!qu.empty())
        {
            pair<int, int> ft = qu.front(); qu.pop();
            vis[ft.first][ft.second] = 1;
            for(int i = 0 ; i < 4 ; i++)
            {
                int x = dx[i] + ft.first, y = dy[i] + ft.second;
                if(valid(x, y, n, m) && !vis[x][y] && image[x][y] == image[sr][sc]) 
                    qu.push({x, y}), image[x][y] = color;
            }
        }
        image[sr][sc] = color;
        return image;
    }
};