class Solution {
public:
    string mergeAlternately(string s1, string s2) 
    {
        string ans;
        reverse(s1.begin(), s1.end()), reverse(s2.begin(), s2.end()); 
        
        while(!s1.empty() && !s2.empty()) 
        {
            ans.push_back(s1.back()), ans.push_back(s2.back());
            s1.pop_back(), s2.pop_back();
        }
        reverse(s1.begin(), s1.end()), reverse(s2.begin(), s2.end());
        ans +=s1, ans +=s2;
        
        return ans;
    }
};