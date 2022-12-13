class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) 
    {
        int l = 0 , r = v.size() - 1;
        vector<int> ans;
        
        while(l <= r)
        {
            if(abs(v[l]) > abs(v[r])) ans.push_back(v[l] * v[l++]);
            else if(abs(v[l]) < abs(v[r])) ans.push_back(v[r] * v[r--]);
            else ans.push_back(v[r] * v[r--]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};