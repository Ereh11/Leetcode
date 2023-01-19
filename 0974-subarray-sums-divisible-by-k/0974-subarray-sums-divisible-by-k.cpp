class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int n = nums.size(), ans = 0, su = 0;
        vector<int> frq(k, 0); frq[0]++;
       
        
        for(int i = 0; i<n; i++) 
        {
            su = (su + (nums[i] % k) + k) % k;
            ans += frq[su];
            frq[su]++;
        }
        
        return ans;
    }
};


/*
*/