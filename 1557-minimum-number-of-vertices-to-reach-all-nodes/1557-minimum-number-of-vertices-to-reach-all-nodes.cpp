class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int> income(n), ans;
        for(auto& it: edges) income[it[1]]++;
        
        for(int i = 0 ; i < n ; i++)
            if(!income[i]) ans.push_back(i);
        
        return ans;
    }
};