class LFUCache {
public:
    unordered_map<int, int> ump;
    unordered_map<int, int> frq;
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int, int>>>>pq;
    int sz = 0, fq;
    LFUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
       if(ump.find(key)==ump.end())return -1;
        put(key,ump[key]);
        return ump[key];
    }
    
    void put(int key, int value) 
    {
       if(!sz) return;
       if(ump.find(key) == ump.end()&& ump.size() == sz)
       {
          while(ump.size() == sz)
            {
                auto x = pq.top();
              
                if(frq[x.second.second] == x.first)
                    ump.erase(x.second.second), frq.erase(x.second.second);
                
                pq.pop();
            }
       }
        ump[key] = value;
        frq[key]++;
        pq.push({frq[key], {fq++,key}});
    }
};

/*
*/