class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int indx = 0;
        for(auto& it: nums)
            if(it != val) nums[indx++] = it;
        
        return indx;
    }
};