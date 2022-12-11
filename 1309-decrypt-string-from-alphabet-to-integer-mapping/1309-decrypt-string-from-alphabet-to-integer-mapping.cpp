class Solution {
public:
    string freqAlphabets(string s) {
        string ans, tp;
        for(int i = 0; i < s.size(); i++)
        {
            if(i + 2 < s.size() && s[i + 2] == '#') 
            {
                tp += s[i], tp += s[i + 1];
                ans.push_back(char(stoi(tp) + 96)), i +=2;
            }
            else
                tp+=s[i], ans.push_back(char(stoi(tp) + 96));
            tp.clear();
        }
        
        return ans;
    }
};