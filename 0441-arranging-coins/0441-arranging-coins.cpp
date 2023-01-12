class Solution {
public:
    int arrangeCoins(int n) 
    {
        long long l = 0, r= 1e9, mid;
        while( l <= r)
        {
            mid = ((l + r) >> 1);
            long long su = (mid * (mid + 1)) / 2;
            if(su > n) r = mid - 1;
            else l = mid + 1;
        }
        return l - 1;
    }
};