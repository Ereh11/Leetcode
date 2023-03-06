class Solution {
public:
    int r, c;
    bool valid(int x, int y) { return x >= 0 && x < r && y >= 0 && y < c; }
    int xd[4] = {1 , -1, 0 , 0};
    int yd[4] = {0 , 0, 1 , -1};
    
    int islandPerimeter(vector<vector<int>>& grid) {
        r = grid.size(), c = grid[0].size(); 
        int ans = 0;
        
        for(int i = 0 ; i < r; i++) 
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 0) continue;
                
                for(int v = 0; v < 4; v++)
                {
                    int x = xd[v] + i, y = yd[v] + j; 
                    ans += (!valid(x, y) || grid[x][y] == 0);
                }
                
            }
        }
        
        return ans;
    }
};