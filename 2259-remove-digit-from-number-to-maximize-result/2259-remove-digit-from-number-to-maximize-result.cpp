class Solution {
public:
    string removeDigit(string s, char d) {
        
        string ans, mx = "";
        for(int i = 0 ; i < s.size() ; i++)
        {
            
            if(s[i] == d) ans =  s.substr(0, i) + s.substr(i + 1,  s.size());
            
            mx = max(mx, ans);
        }
        
        
        
        return mx;
    }
};