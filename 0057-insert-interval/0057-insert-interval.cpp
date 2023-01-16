class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& newInterval) 
    {
        vector<vector<int>> ans;
        v.push_back(newInterval);
        sort(v.begin(), v.end());
        
        for(int i = 0 ; i < v.size() ; i++)
            if(i + 1 < v.size() && v[i + 1][0] <= v[i][1])
            {
                v[i + 1][0] = v[i][0], v[i + 1][1] = max(v[i + 1][1], v[i][1]);
                v[i][0] = -1;
            }
        
        for(int i = 0 ; i < v.size() ; i++)
            if(~v[i][0]) ans.push_back(v[i]);
        
        return ans;
    }
};