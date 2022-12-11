// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long st = 1, en = n;
        
        while(st <= en )
        {
            long long mid = ((st + en) >> 1);
            if(isBadVersion(mid) == false) st = mid + 1;
            else en = mid - 1;
        }
        
        return st;
    }
};