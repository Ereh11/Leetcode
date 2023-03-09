class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = 0, r = 0;
        vector<int> v;
        
        while(l < n + m)
        {
            if(l < m && r < n && nums1[l] <= nums2[r]) 
                v.push_back(nums1[l++]);
            else if(l < m && r < n && nums1[l] > nums2[r]) 
                v.push_back(nums2[r++]);
            else if(l == m && r < n) 
                v.push_back(nums2[r++]);
            else if(r == n && l < m) 
                v.push_back(nums1[l++]);
            else 
                break;
        }
        
        nums1 = v;
    }
};