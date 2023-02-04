class Solution {
public:
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int n, m;
    bool valid(int r, int c){ return (r >= 0 && r < n && c >= 0 && c < m); }
    
    void BFS(int sr, int sc, int color, vector<vector<int>>& image)
    {
        queue<pair<int, int>> qu;
        int colorsource = image[sr][sc];
        qu.push({sr, sc});  image[sr][sc] = color;
        
        while(!qu.empty())
        {
            pair<int, int> ft = qu.front(); qu.pop();
            for(int i = 0 ; i < 4 ; i++)
            {
                int x = dx[i] + ft.first, y = dy[i] + ft.second;
                if(valid(x, y) && image[x][y] == colorsource) 
                    qu.push({x, y}), image[x][y] = color;
            }
        }
        
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        if(color == image[sr][sc]) return image;
        n = image.size(), m = image[0].size();
        BFS(sr, sc, color, image);
        return image;
    }
};