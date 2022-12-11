class Solution {
public:
    bool isAlienSorted(vector<string>& words, string s) {
        unordered_map<char, char> ump;
        
        for(int i = 0 ; i < s.size(); i++) ump[s[i]] = 'a' + i;
        
        for(auto& it: words)
            for(auto& i: it) i = ump[i];
        
        return is_sorted(words.begin(), words.end());
    }
};