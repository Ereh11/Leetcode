class Solution {
public:
    void solve(int indx, int sumNow, vector<vector<int>> &res, vector<int> &out, int &k, int &sumAll)
    {
        if(out.size() == k && sumNow == sumAll) {
            res.push_back(out);
            return;
        }
        
        for(int i = indx ; i <= 9; i++)
        {
            out.push_back(i);
            sumNow += i;
            
            solve(i + 1, sumNow, res, out, k, sumAll);
            
            sumNow -= i;
            out.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> out;
        
        solve(1, 0, res, out, k, n);
        
        return res;
    }
};