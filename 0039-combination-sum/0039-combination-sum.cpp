class Solution {
public:
    void solve(vector<int> &cands, vector<vector<int>> &res, vector<int> out, int &sum, int indx)
    {
        if(sum == 0)  {
            res.push_back(out);
            return;
        }
        
        
        for(int i = indx; i < cands.size(); i++)
        {
            if(sum - cands[i] >= 0) {
                out.push_back(cands[i]);
                sum -= cands[i];
                
                solve(cands, res, out, sum, i);
                
                out.pop_back();
                sum += cands[i];
            }
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> frq(41), cands, out;
        vector<vector<int>> res;
        
        for(auto& it: candidates) 
            if(!frq[it]) {
                cands.push_back(it);
                frq[it] = 1;
            }
        
        
        solve(cands, res, out, target, 0);
        
        return res;
    }
};