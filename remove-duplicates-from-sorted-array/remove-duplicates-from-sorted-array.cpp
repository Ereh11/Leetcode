class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int indx = 0, val = 101;
        for(auto& it: nums)
        {
            if(it != val){
                nums[indx++] = it, val = it;
            }
        }
        
        return indx;
    }
};