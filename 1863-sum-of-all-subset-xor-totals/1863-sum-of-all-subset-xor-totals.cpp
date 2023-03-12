class Solution {
public:
    
    void solve(vector<int>& nums, int &sum, int res, int indx)
    {
        if(indx == nums.size()){
            sum += res;
            return;
        } 
        
        
        solve(nums, sum, (res ^ nums[indx]), indx + 1);
       
        solve(nums, sum, res, indx + 1);    
    }
    
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        
        solve(nums, sum, 0, 0);
        
        return sum;
    }
};