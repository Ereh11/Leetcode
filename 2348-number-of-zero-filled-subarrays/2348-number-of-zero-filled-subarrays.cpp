class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cntZero = 0, ans = 0, sz = nums.size();
        
        for(int i = 0 ; i < sz; i++)
        {
            if(!nums[i]) {
                cntZero++;
            }
            
            if(nums[i] || i == sz - 1) {
                ans += ((cntZero * (cntZero + 1)) >> 1), cntZero = 0;
            }
        }
        
        return ans;
    }
};