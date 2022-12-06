class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(auto& it: nums) ans *= (!it ? 0 : (it < 0 ? -1 : 1));
        
        return ans;
    }
};