class CombinationIterator {
public:
    set<string> se;
    string ans;
    void solve(string &s, int &sz, int indx)
    {
       
        for(int i = indx; i < s.size() ; i++) 
        {
            ans.push_back(s[i]);
            
            if(ans.size() == sz && se.find(ans) == se.end())
                se.insert(ans);
            
            solve(s, sz, i + 1);
            ans.pop_back();
        }
    }
    
    CombinationIterator(string characters, int combinationLength) {
        ans.clear(), se.clear();
        solve(characters, combinationLength, 0);
    }
    
    string next() {
        string res = *se.begin();
        
        se.erase(se.begin());
        
        return res;
    }
    
    bool hasNext() {
        return (!se.empty());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */