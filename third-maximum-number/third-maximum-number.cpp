class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> se;
        vector<int> ans;
        for(auto& it: nums)  se.insert(it);
        
        for(auto it = se.begin() ; it != se.end(); it++) 
            ans.push_back(*it);
        
        return (ans.size() < 3 ? ans.back() : ans[ans.size() - 3]);
    }
};