class Solution {
public:
    bool halvesAreAlike(string s) 
    {
        int cnt = 0;
        
        for(int i = 0 ; i < s.size() ; i++) s[i] = tolower(s[i]);
        
        for(int i = 0 ; i < s.size() / 2 ; i++)
            if(s[i]=='e'||s[i]=='a'||s[i]=='u'||s[i]=='i'||s[i]=='o') cnt++;
        
        for(int i = s.size() / 2 ; i < s.size() ; i++)
            if(s[i]=='e'||s[i]=='a'||s[i]=='u'||s[i]=='i'||s[i]=='o') cnt--;
        
        return (cnt == 0);
    }
};