class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n = nums.size(), l = 0, r = n - 1, mid;
        if(n == 1) return nums[0];
        while(l <= r)
        {
            mid = ((l + r) >> 1);
            int prev = (mid + n - 1) % n, next = (mid + 1) % n;
            
            if(nums[mid] != nums[prev] && nums[mid] != nums[next]) 
                return nums[mid];
            else if(((mid & 1) && nums[mid] == nums[prev]) || (!(mid & 1) && nums[mid] == nums[next]))
                 l = mid + 1;
            else 
                 r = mid - 1;
        }
        
        return 0;
    }
};