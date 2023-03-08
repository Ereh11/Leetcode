class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        
        for(auto& it: nums) {
            int sz = int(log10(it)) + 1;
            ans += (!(sz & 1));
        }
        
        return ans;    
    }
};