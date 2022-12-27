class Solution {
public:
    string removeDigit(string s, char d) {
        
        string ans, mx = "";
        for(int i = 0 ; i < s.size() ; i++)
        {
            string s1 = (!i) ? "" : s.substr(0, i);
            string s2 = s.substr(i + 1,  s.size());
            
            if(s[i] == d) ans =  s1 + s2;
            
            mx = max(mx, ans);
        }
        
        
        
        return mx;
    }
};