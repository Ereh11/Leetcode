class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int n, m;
    vector<vector<int>> dist, vis;
    
    bool check(int r, int c) { return(r>=0 && r<n && c>=0 && c<m && !vis[r][c]); }
    
    int BFS(int r, int c, vector<vector<char>>& maze)
    {
        queue<pair<int, int>> qu; qu.push({r, c});
        int ans = INT_MAX;
        while(!qu.empty())
        {
            auto ft = qu.front(); qu.pop();
            vis[ft.first][ft.second] = 1;
            for(int i = 0 ; i < 4; i++)
            {
                int x = ft.first + dx[i], y = ft.second + dy[i];
                if((ft.first == n - 1 || ft.second == m - 1 || !ft.first || !ft.second) && (ft.first != r || ft.second != c))
                    ans = min(ans, dist[ft.first][ft.second]);
                
                if(check(x, y) && maze[x][y] == '.')
                {
                    qu.push({x, y}), dist[x][y] = dist[ft.first][ft.second] + 1, vis[x][y] = 1;
                } 
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        n = maze.size(), m = maze[0].size();
        vis.resize(n, vector<int>(m)), dist.resize(n, vector<int>(m));
        return BFS(e[0], e[1], maze);
    }
};