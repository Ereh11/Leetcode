class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string _s = s + s;
    
        return _s.substr(1, _s.size() - 2).find(s) != _s.npos;
    }
};