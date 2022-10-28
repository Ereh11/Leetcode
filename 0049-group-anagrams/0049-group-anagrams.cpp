class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
      
       vector<pair<string, int>> v;
       vector<vector<string>> gp;
    
       for(int i = 0 ; i < strs.size(); i++)
       {
           string s = strs[i];
           sort(s.begin(), s.end());
           v.push_back({s, i});
       }
        
       sort(v.begin(), v.end());
       vector<string> ans;
        
       for(int i = 0 ; i < strs.size(); i++)
       {
           if(i + 1 != strs.size() && v[i].first == v[i + 1].first)
               ans.push_back(strs[v[i].second]);
           else if(i + 1 == strs.size() || v[i].first != v[i + 1].first)
               ans.push_back(strs[v[i].second]);
           if(i + 1 == strs.size() ||  v[i].first != v[i + 1].first) 
               gp.push_back(ans), ans.clear();
       } 
        
        return gp;
    }
};