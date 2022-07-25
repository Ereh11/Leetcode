class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=0, buy= prices[0];
        for(int i= 0 ; i < prices.size(); i++) 
        {
            buy= min(buy, prices[i]);
            if(prices[i] >= buy) sell= max(sell, prices[i] - buy);
        }
        return sell;
    }
};