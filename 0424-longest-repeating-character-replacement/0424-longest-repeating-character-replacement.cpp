class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int l = 0, r = 0, ans = 0;
        vector<int> frq(27); frq[s[0] - 'A']++;
        while(l <= r && r < s.size())
        {
            int mx = 0;
            for(auto& it: frq) mx = max(mx, it);
                
            if((r - l + 1) - mx <= k) 
            {
               ans = max(ans, (r - l + 1)), r++;
               if(r < s.size()) frq[s[r] - 'A']++;
            }
            else 
                frq[s[l] - 'A']--, l++;
            
        }
        
        return ans;
    }
};