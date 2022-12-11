class Solution {
public:
    int search(vector<int>& nums, int t) 
    {
       int st = 0, en = nums.size() - 1;
        
       while(st <= en)
       {
           int mid = ((st + en) >> 1);
           if(nums[mid] == t) return mid;
           else if(nums[mid] > t) en = mid - 1;
           else st = mid + 1;
       }
        
       return -1;
    }
};