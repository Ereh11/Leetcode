class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int p1 = 0, p2 = 0, ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        while(p1 < g.size() && p2 < s.size())
        {
            if(g[p1] <= s[p2])
                ans++, p1++, p2++;
            else 
                p2++;
        }
        
        return ans;
    }
};