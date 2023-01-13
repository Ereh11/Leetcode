class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> frq(123);
        int ans = 0;
        for(auto& it: s) frq[it]++;
        for(auto& it: s)
        {
            if(!(frq[it] & 1)) ans +=frq[it], frq[it] = 0;
            else if(frq[it] > 1) ans += (frq[it] - 1), frq[it] = 0;
        }
        
        ans +=(s.size() - ans > 0);
        
        return ans;
    }
};