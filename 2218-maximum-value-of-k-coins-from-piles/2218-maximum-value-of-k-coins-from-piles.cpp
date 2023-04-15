class Solution
{
    private: 
        int dp[1001][2001];
    public:
        int solver(vector<vector < int>> &arr, int coins, int idx=0)
        {

            if (idx >= arr.size() || coins == 0) 
                return 0;

            if (~dp[idx][coins]) 
                return dp[idx][coins];

            int ans = INT_MIN;


            ans = solver(arr, coins, idx + 1);


            int sz = arr[idx].size();
            int sum = 0;

            for (int i = 0; i < min(coins, sz); i++)
            {
                sum = sum + arr[idx][i];
                ans = max(ans, sum + solver(arr, coins - (i + 1), idx + 1));
            }

            return dp[idx][coins] = ans;
        }

        int maxValueOfCoins(vector<vector < int>> &piles, int k)
        {
            memset(dp, -1, sizeof(dp));
            return solver(piles, k);
        }
};