class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> mxcol(grid.size()), mxrow(grid.size());
        int ans = 0;
        
        for(int i = 0 ; i < grid.size(); i++) {
            for(int j = 0; j < grid.size(); j++)
            {
                mxcol[i] = max(mxcol[i], grid[i][j]);
                mxrow[j] = max(mxrow[j], grid[i][j]);
            }
        }
        
        for(int i = 0 ; i < grid.size(); i++) {
            for(int j = 0; j < grid.size(); j++)
            {
                ans += min(mxcol[i], mxrow[j]) - grid[i][j];
            }
        }
        
        return ans;
    }
};