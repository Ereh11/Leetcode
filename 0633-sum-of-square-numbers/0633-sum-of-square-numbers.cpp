class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i = 0 ; i * i <= c ; i++)
        {
            long long l = 0, r = c - (i * i), t = c - (i * i);
            while(l <= r)
            {
                long long mid = ((l + r) >> 1), b = mid * mid;
                if(b == t) return true;
                if(b > t)  r = mid - 1;
                else l = mid + 1;
            }
        }
        return false;
    }
};
