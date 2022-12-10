class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        vector<int> frq(101); int ans = 0;
        
        for(auto& it: nums) frq[it]++;
        for(auto& it: nums){
            frq[it]--;
            if(frq[it] > 0) ans +=frq[it];
        }
        
        return ans;
    }
};