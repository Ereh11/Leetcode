class Solution {
public:
    void solve(int indx, vector<vector<int>> &res, vector<int> &out, int &k, int &n)
    {
        if(out.size() == k) {
            res.push_back(out);
            return;
        }
        
        for(int i = indx ; i <= n; i++)
        {
            out.push_back(i);
            
            solve(i + 1, res, out, k, n);
            
            out.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        vector<int> out;
        
        solve(1, res, out, k, n);
        
        return res;
    }
};