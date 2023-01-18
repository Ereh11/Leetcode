class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v; 
        vector<int> ans;
        for(int i = 0 ; i < mat.size(); i++)
        {
            int cnt = 0;
            for(int j = 0 ; j < mat[0].size(); j++) cnt +=mat[i][j];
            v.push_back({cnt, i});
        }
        sort(v.begin(), v.end());
        
        for(int i = 0; i < v.size() && k; i++) 
                k--, ans.push_back(v[i].second); 
        
        return ans;
    }
};