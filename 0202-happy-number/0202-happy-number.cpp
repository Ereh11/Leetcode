class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> mp;
        int ans = 0;
        
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