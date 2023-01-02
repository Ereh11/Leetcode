class Solution {
public:
    bool check(string &s)
    {
        
        if(s[0] <= 90  && s.size() > 1 && s[1] >= 97)
        {
            for(int i = 1; i < s.size(); i++) 
                if(s[i] < 97) return false;
        }
        else if(s[0] >= 97)
        {
            for(auto& it: s) 
                if(it < 97) return false;
        }
        else
        {
            for(auto& it: s) 
                if(it > 90) return false;
        }
        
        return true;
    }
    bool detectCapitalUse(string word) {
        return check(word);
    }
};