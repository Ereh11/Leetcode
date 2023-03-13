class Solution {
public:
    bool isValid(int r, int c) {
        return (r >= 0 && r < 4 && c >=0 && c < 3 && !(r == 3 && !c) && !(r == 3 && c == 2));
    }
    
    int solve(int r, int c, int sz, int &MOD, int dp[5][4][5001],int dx[8],int dy[8])
    {
        if(!isValid(r, c) || sz <= 0) 
            return 0;
        
        if(sz == 1) 
            return 1;
       
        if(~dp[r][c][sz]) 
            return dp[r][c][sz];
         
        int res = 0;
        
        for(int i = 0 ; i < 8 ; i++) {
            int x = dx[i] + r, y = dy[i] + c;
            if(isValid(x, y)) {
                res = ( res % MOD + (solve(x, y, sz - 1, MOD, dp, dx, dy)) % MOD) % MOD;
            }
        }
        
        return dp[r][c][sz] = res % MOD;
    }
    
    int knightDialer(int n) {
        int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2}; 
        int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
        int dp[5][4][5001];
        
        int ans = 0;
        int MOD = (int)1e9 + 7;
        memset(dp, -1, sizeof(dp));
        
        for(int i = 0 ; i < 4 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                ans = ((ans % MOD) + (solve(i, j, n, MOD, dp, dx, dy) % MOD)) % MOD;
        
        return ans;
    }
};
