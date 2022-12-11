class Solution {
public:
    string toLowerCase(string s) {
        for(auto& it: s) it = tolower(it);
        return s;
    }
};