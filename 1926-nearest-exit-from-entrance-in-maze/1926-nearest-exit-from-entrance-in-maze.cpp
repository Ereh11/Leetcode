class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int n, m;
    
    bool check(int r, int c) { return(r >= 0 && r < n && c >= 0 && c < m); }
    
    int BFS(int entrance_x, int entrance_y, vector<vector<char>>& maze)
    {
        queue<pair<pair<int, int>, int>> qu; qu.push({{entrance_x, entrance_y}, 0});
        
        while(!qu.empty())
        {
            auto ft = qu.front(); qu.pop();
            int r = ft.first.first, c = ft.first.second, val = ft.second;
            maze[r][c] = '+';
            
            for(int i = 0 ; i < 4; i++)
            {
                int x = r + dx[i], y = c + dy[i];
                if((r == n - 1 || c == m - 1 || !r || !c) && (r != entrance_x || c != entrance_y))
                    return val;
                
                if(check(x, y) && maze[x][y] == '.')
                    qu.push({{x, y}, val + 1}),  maze[x][y] = '+';
            }
        }
        
        return -1;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        n = maze.size(), m = maze[0].size();
        
        return BFS(e[0], e[1], maze);
    }
};