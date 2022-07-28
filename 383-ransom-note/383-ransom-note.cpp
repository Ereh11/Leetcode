class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> frq(26);
        
        for(auto& it: magazine) frq[it-97]++;
        for(auto& it: ransomNote)
            if(frq[it-97]) frq[it-97]--;
            else return false;
        
        return true;
    }
};