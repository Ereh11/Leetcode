class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans= 0;
        vector<int> sfx(prices.size() + 1);
        for(int i= prices.size() - 1 ; i >= 0; i--) sfx[i] = max(sfx[i + 1], prices[i]);
        for(int i= 0 ; i < prices.size()-1; i++) 
            ans= max(ans, sfx[i+1] - prices[i]);
        return ans;
    }
};