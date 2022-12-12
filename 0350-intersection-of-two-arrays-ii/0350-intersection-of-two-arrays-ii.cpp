class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        unordered_map<int, pair<int, int>>frq;
        for(int i= 0 ; i < nums1.size(); i++) frq[nums1[i]].first++;
        for(int i= 0 ; i < nums2.size(); i++) frq[nums2[i]].second++;
        for(int i= 0 ; i < nums2.size(); i++)
        { 
            frq[nums2[i]].first--, frq[nums2[i]].second--;
            if(frq[nums2[i]].first >=0 && frq[nums2[i]].second >=0) ans.push_back(nums2[i]);
        }
        
        return ans;
    }
};