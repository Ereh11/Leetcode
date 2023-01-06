class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0;
        sort(costs.begin(), costs.end());
        
        for(auto& it: costs) 
            if(it <= coins) ans++, coins -=it;
        
        return ans;
    }
};