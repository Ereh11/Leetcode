class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
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