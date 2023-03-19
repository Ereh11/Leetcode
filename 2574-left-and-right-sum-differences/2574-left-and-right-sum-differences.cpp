class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> ans;
        int sumAll = 0, sumLeft = 0;
        
        for(auto& it: nums) {
            sumAll += it;
        }
        for(int i = 0 ; i < nums.size() ; i++) {
            sumLeft += ((i) ? nums[i - 1] : 0);
            ans.push_back(abs(2 * sumLeft - (sumAll - nums[i])));
        }
        
        return ans;
    }
};