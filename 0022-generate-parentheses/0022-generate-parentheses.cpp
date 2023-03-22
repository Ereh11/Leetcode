class Solution {
public:
    void solve(string ans, int closeNum, int openNum, int &n, vector<string> &res)
    {
        if(ans.size() == 2 * n){
            res.push_back(ans);
            return;
        }
            
        if(openNum < n)
        {
            ans.push_back('(');
            solve(ans, closeNum, openNum + 1, n, res);
            ans.pop_back();
        }
        
        if(closeNum < openNum)
        {
            ans.push_back(')');
            solve(ans, closeNum + 1, openNum, n, res);
            ans.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve("", 0, 0, n, res);
        return res;
    }
};