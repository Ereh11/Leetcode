class Solution {
public:
    bool wordPattern(string p, string s) 
    {
        string tp; vector<string> v;
        for(int i = 0 ;i < s.size(); i++) {
            if(s[i] != 32) tp.push_back(s[i]);
            if(i == s.size() - 1 || s[i] == 32) v.push_back(tp), tp.clear();
        }
        
        if(v.size() != p.size()) return false;
        
        unordered_map<char, string> ump;
        unordered_set<string> ex;
        for(int i = 0; i < v.size(); i++)
        {
            if(ump.find(p[i]) != ump.end()){
                if(ump[p[i]] != v[i]) return false;
            }
            else{
                if(ex.find(v[i]) != ex.end()) return false;
                ump[p[i]] = v[i], ex.insert(v[i]);
            }
        }
        
        return true;
    }
};
