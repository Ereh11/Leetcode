class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> ans;
        
        for(int i = 0 ; i < s2.size() ; i++)
            if(s1[i] != s2[i]) ans.push_back(i);
        
       if(ans.size() == 2) swap(s2[ans[0]], s2[ans[1]]);
        
        return s1 == s2;
    }
};