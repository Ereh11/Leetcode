class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        //char c;
        vector<int> frqs(26), frqt(26);
        for(auto& it: t) frqt[it - 97]++;
        for(auto& it: s) frqs[it - 97]++;
            
        for(auto& it: t) if(frqt[it - 97] != frqs[it - 97]) return it;
        
        return 'a';
    }
};