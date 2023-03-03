class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int p1 = 0, p2 = 0, n = s.size(), ans = 0;
        vector<int> frq(260, 0);
        
        while(p2 < n)
        {
            frq[s[p2]]++;            
            while(frq[s[p2]] > 1)
                frq[s[p1++]]--;
           
            ans = max(p2 - p1 + 1, ans);
            p2++;
        }
        
        return ans;
    }
};