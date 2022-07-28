class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> frq(26);
        for(auto& it: s) frq[it-97]++;
        for(int i = 0 ; i < s.size() ; i++)
            if(frq[s[i]-97] == 1) return i;
        return -1;
    }
};