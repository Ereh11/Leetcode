class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, r = x, sq, mid;
        
        while(l <= r)
        {
            mid = ((l + r) >> 1);
            sq = mid * mid;
            if(sq == x) return mid;
            if(sq > x) r = mid - 1;
            else l = mid + 1;
        }
        return l - 1;
    }
};