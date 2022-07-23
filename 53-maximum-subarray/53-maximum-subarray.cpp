class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, sum = INT_MIN;
        
        for(auto& it: nums) {
            curr = max(it, curr + it);
            sum = max(sum, curr);
           
        }
        
        return sum;
    }
};