class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, char> ump;
        unordered_map<char, int>frq;
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(ump.find(s[i]) == ump.end() && !frq[t[i]]) ump[s[i]] = t[i], frq[t[i]] = 1;
            else if(ump[s[i]] != t[i]) return false;
        }
        return true;
    }
};