class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 0, r = num, sq = 0, mid = 0;
        
        while(l <= r)
        {
            mid = ((l + r) >> 1);
            sq = mid * mid;
            if(sq == num) return true;
            if(sq > num) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
    /*
    return (int)sqrt(num) == sqrt(num);
    
    */
};