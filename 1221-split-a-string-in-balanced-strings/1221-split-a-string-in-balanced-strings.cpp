class Solution {
public:
    int balancedStringSplit(string s) {
        
        int L = 0, R = 0, ans = 0;
        
        for(auto& it: s)
        {
            L += (it == 'L');
            R += (it == 'R');
            if(L == R){
                ans++;
                L = R = 0;
            }
        }
        
        return ans;
    }
};