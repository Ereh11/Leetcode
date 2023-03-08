class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) 
    {
        int n = v.size() - 1;
        int l = 0 , r = n, indx = n;
        vector<int> ans(n + 1);
        
        
        while(l <= r)
        {
            if(abs(v[l]) <= abs(v[r])) 
               ans[indx--] = v[r] * v[r--]; 
            else 
               ans[indx--] = v[l] * v[l++];
        }
        
        return ans;
    }
};