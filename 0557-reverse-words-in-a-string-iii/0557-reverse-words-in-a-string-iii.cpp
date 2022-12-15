class Solution {
public:
    string reverseWords(string s) {
        string ans, tp;
        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i] != 32) tp.push_back(s[i]);
            if(s[i] == 32 || i == s.size() - 1) 
            {
                reverse(tp.begin(), tp.end());
                if(s[i] == 32) tp.push_back(' ');
                ans +=tp, tp.clear();
            }
        }
        return ans;
    }
};