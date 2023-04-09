

//''

class Solution {
public:
    int trailZero(int n)
    {        
        int cnt = 0;
        
        while(n)
        {
            cnt += n / 5;
            n /=5;
        }
        
        return cnt;
    }
    
    int preimageSizeFZF(int n) 
    {
        long long l = 0, r = 1000000000, mid;
        
        if(n == l || n == r)
            return 5; 
        
        while(l <= r)
        {      
            mid = l + (r - l) / 2;
            
            int cnt = trailZero(mid);

            if(cnt == n )
                return 5;
            else if(cnt > n)
                r = mid - 1;
            else 
                l = mid + 1;
        }
    
        return 0;
    }
};