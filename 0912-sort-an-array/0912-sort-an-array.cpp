class Solution {
public:
    vector<int> counting_sort(vector<int>& nums)
    {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> frq; vector<int> ans;
        
        for(auto& it: nums)  
            frq[it]++;
        for(int i = mn; i <= mx; i++)
            while(frq[i]) {
                ans.push_back(i), frq[i]--;
            }
        
        return ans;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        return counting_sort(nums);
    }
};