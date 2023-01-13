class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int indx = 0;
        
        for(auto &it: t)
            if(it == s[indx]) indx++;
        
        return indx == s.size();
    }
};