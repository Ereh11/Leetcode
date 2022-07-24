class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1= 0, p2= 0;
        vector<int> v;
        while(p1 < n + m)
        {
            if(p1 < m && p2 < n && nums1[p1] <= nums2[p2]) v.push_back(nums1[p1++]);
            else if(p1 < m && p2 < n && nums1[p1] > nums2[p2]) v.push_back(nums2[p2++]);
            else if(p1 == m && p2 < n) v.push_back(nums2[p2++]);
            else if(p2 == n && p1 < m) v.push_back(nums1[p1++]);
            else break;
        }
        nums1 = v;
    }
};