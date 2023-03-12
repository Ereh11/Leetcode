class Solution {
public:
    vector<string> res;
    void solve(string &s, int indx, string ans)
    {
        if(indx == s.size()) {
            res.push_back(ans);
            return;
        }
        
        if(s[indx] >= 48 && s[indx] <= 57) {
            ans += s[indx];
            solve(s, indx + 1, ans);
        }
        else {
            
            ans += toupper(s[indx]);
            solve(s, indx + 1, ans);
            ans.pop_back();

            ans += tolower(s[indx]);
            solve(s, indx + 1, ans);
            ans.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        
        solve(s, 0, "");
        return res;
    }
};