class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        char c;
        for(auto& it: t)
            if(count(s.begin(), s.end(), it) != count(t.begin(), t.end(), it)) c =it;
        
        return c;
    }
};