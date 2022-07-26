class Solution {
public:
    bool check(int r, int c, int n, int m) { return(r>=0 && r<n && c>=0 && c<m); }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int dx[] = { 1, -1, 0, 0 };
        int dy[] = { 0, 0, 1, -1 };
        queue<pair<int, int>> qu; qu.push({sr, sc});
        int n= image.size(), m= image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        vis[sr][sc]= 1;
        while(!qu.empty())
        {
            pair<int, int> ft= qu.front(); qu.pop();
            for(int i=0 ;i < 4; i++)
            {
                int x= dx[i] + ft.first, y= dy[i] + ft.second;
                if(check(x, y, n, m) && !vis[x][y] && image[x][y] == image[sr][sc]) 
                    qu.push({x, y}), image[x][y]= color, vis[x][y] = 1;
            }
        }
        image[sr][sc]= color;
        return image;
    }
};