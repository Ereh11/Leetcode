class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> frqs(26), frqt(26);
        
        for(auto& it: s) frqs[it-97]++;
        for(auto& it: t) frqt[it-97]++;
        
        for(auto& it: t)
            if(frqs[it - 97]) frqs[it-97]--;
            else return false;
        
        for(auto& it: s)
            if(frqt[it - 97]) frqt[it-97]--;
            else return false;
        
        return true;
    }
};