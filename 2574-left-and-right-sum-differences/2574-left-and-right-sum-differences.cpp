class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int sfx = 0, pfx = 0;
        
        for(auto& it: nums) {
            sfx += it;
        }
        
        for(auto& it: nums) 
        {
            int val = it;
            pfx += it;
            
            it = abs(sfx - pfx);
            
            sfx -= val;
        }
        
        return nums;
    }
};