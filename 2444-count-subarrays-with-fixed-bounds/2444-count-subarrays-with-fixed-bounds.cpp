class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long ans = 0;
        int mn = -1, mx = -1, leftBound = -1;
      
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (nums[i] < minK || nums[i] > maxK)
                leftBound = i;
            
            if (nums[i] == minK) 
                mn = i;
            if (nums[i] == maxK)
                mx = i;

            ans += max(0, min(mn, mx) - leftBound);
        }
        
        return ans;
    }
};