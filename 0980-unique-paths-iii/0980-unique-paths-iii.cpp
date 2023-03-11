class Solution {
public:
    int n, m, ans = 0;
    int XD[4] = {1, -1, 0, 0};
    int YD[4] = {0, 0, 1, -1};
    pair<int, int> st, end;
    int cntPossibleCell = 0;
    
    bool isValid(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < m); }
        
    int solve(vector<vector<int>>& grid, int r, int c, int cntCell)
    {
        
       if(r == end.first && c == end.second && cntCell == cntPossibleCell)
            return 1;
        
        grid[r][c] = -1;
        
        for(int i = 0 ; i < 4 ; i++) 
        {  
            int x = XD[i] + r, y = YD[i] + c;
            
            if(isValid(x, y) && ~grid[x][y])
                ans += solve(grid, x, y, cntCell + 1); 
        }
        
        grid[r][c] = 0;
        
        return 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++) 
            {
                if(~grid[i][j])   
                    cntPossibleCell++;
                if(grid[i][j] == 1)   
                    st = {i, j};
                if(grid[i][j] == 2)  
                    end = {i, j};
            }
       
        solve(grid, st.first, st.second, 1);
        return ans;
    }
};