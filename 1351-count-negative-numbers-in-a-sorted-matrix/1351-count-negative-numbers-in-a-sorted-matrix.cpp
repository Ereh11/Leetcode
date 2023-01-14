class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size(), indx = 0, ans = 0;
        while(indx < n)
        {
            int cnt = 0,  r = m - 1;
            while(~r && grid[indx][r] < 0) r--, cnt++;
            ans += cnt, indx++;
        }
        return ans;
    }
};