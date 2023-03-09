class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int indx = 0;
       for(int i = 0 ; i < nums.size(); i++)
       {
           if(nums[i] && indx == i) 
               indx++;
           else if(nums[i] && i != indx)
               nums[indx++] = nums[i], nums[i] = 0;
       }
    }
};