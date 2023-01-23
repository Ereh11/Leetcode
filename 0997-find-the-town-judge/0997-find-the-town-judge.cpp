class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v[n + 1]; vector<bool> frq(n + 1);
        
        for(auto& it: trust) v[it[1]].push_back(it[0]), frq[it[0]] = 1;
        
        for(int i = 1; i <= n ; i++) 
            if(v[i].size() == n - 1 && !frq[i]) return i;
        
        return -1;
    }
};