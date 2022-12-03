class Solution {
public:
    string frequencySort(string s) {
        map<char, int> frq;
        vector<pair<int, char>> ans;
        for(auto& it: s)
            frq[it]++;
        for(auto& it : frq)
            ans.push_back({it.second, it.first});
        
        sort(ans.begin(), ans.end(), greater<pair<int, char>>());
        
        s.clear();
        for(auto& it: ans)
            while(it.first > 0) s.push_back(it.second), it.first--;
        
        return s;
        
    }
};