class Solution {
public:
    bool isHappy(long long n) {
        map<int, bool> mp;
        long long ans = 0;
        
        while(ans != 1)
        {
            ans = 0;
            while(n > 0) ans += ((n % 10) * (n % 10)), n /=10;
            
            n = ans;
    
            if(mp[n]) return 0;
            
            mp[n] = 1;
        }
        
        return 1;
    }
};