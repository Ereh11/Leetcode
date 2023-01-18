class Solution {
public:
    int maxSubarraySumCircular(vector<int>& v) 
    {
        int sumtotal = 0, mxsubarr = -1e5, minsubarr = 1e5;
        int curmn = 0, curmx = 0;
        
        for(auto& it: v)
        {
            sumtotal +=it;
            curmx = max(curmx + it, it);
            curmn = min(curmn + it, it);
            mxsubarr = max(mxsubarr, curmx);
            minsubarr = min(minsubarr, curmn);
        }
        
        return mxsubarr > 0 ? max(mxsubarr, sumtotal  - minsubarr) : mxsubarr;
    }
};


/*

*/