class Solution {
    
    void solve(int n, int &res)
    {
        if(n == 0) 
            return;
        int indx = log2(n);
        int small = pow(2, indx);
        int large = pow(2, indx + 1);
        
        solve(min(n - small, large - n), ++res);
    }
    
public:
    int minOperations(int n) {
        int res = 0;
        solve(n, res);
        return res;
    }
};