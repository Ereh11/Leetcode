class Trie {
public:
    unordered_map<string, int>ump, mp;
    Trie() {
        
    }
    
    void insert(string word) 
    {
        ump[word]++;
        string s;
        for(auto it : word) {
            s.push_back(it);
            if(mp[s]==0) 
                mp[s]++;
        }
    }
    
    bool search(string word) {
        if(ump[word]) 
            return true;
        
        return false;
    }
    
    bool startsWith(string prefix) {
        if(mp[prefix]) 
            return true;
        
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */