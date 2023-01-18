class Solution {
public:
   
    int maxDistance(vector<int>& nums1, vector<int>& nums2) 
    {
        int p1 = 0, p2 = 0, ans = 0;
        
        while(p1 < nums1.size() && p2 < nums2.size())
        {
            if(nums1[p1] > nums2[p2]) 
                p1++;
            else
                ans = max(ans, p2 - p1), p2++;
            
        }
        
        return ans;
    }
};