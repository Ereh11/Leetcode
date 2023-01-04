class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        unordered_map<int, int> mp;
        
        for(auto& it: tasks) mp[it]++;
        
        for(auto& it: mp)
        {
            if(mp[it.first] == 1) return -1;
            else if(!(mp[it.first] % 3)) ans += mp[it.first] / 3;
            else ans += (mp[it.first] / 3) + 1;
        }
        
        return ans;
    }
};