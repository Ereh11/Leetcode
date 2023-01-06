class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumall = 0, sumleft = 0;
        for(auto& it: nums) sumall +=it;
        
        for(int i = 0 ; i <  nums.size() ; i++)
        {
            sumleft += nums[i];
            if(sumleft - nums[i] == sumall - sumleft) return i;
        }
        
        return -1;
    }
};

/*
        solution 1: using two vector prefix and suffix sum 
        vector<int> pfx(10001), sfx(10001); 
        pfx[0] = nums[0], sfx[nums.size() - 1] = nums.back();
        
        for(int i = 1; i < nums.size(); i++)
            pfx[i] += pfx[i - 1] + nums[i];
        
        for(int i = nums.size() - 2; ~i  ; i--)
            sfx[i] += sfx[i + 1] + nums[i];
        
        for(int i = 0; i < nums.size(); i++)
            if(sfx[i] - nums[i] == pfx[i] - nums[i]) return i;
        
        return -1
 */