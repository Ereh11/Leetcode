class Solution {
public:
    struct p{
        bool operator()(pair<int, string> a, pair<int, string> b)
        {
            if(a.first == b.first) 
                return a.second > b.second;
            return a.first < b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> ump;
        vector<string> ans;
        for(auto& it: words) ump[it]++;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, p> pq;
        for(auto& it: ump) 
            pq.push({it.second, it.first});
        
        while(k--) 
            ans.push_back(pq.top().second), pq.pop();
        
        return ans;
    }
};