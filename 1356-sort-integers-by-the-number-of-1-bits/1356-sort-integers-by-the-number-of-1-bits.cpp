class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> ans;
        
        for(auto& it: arr) ans.push_back({ __builtin_popcount(it), it});
        
        sort(ans.begin(), ans.end());
        for(int i = 0 ; i < ans.size(); i++) arr[i] = ans[i].second;
        
        return arr;
    }
};