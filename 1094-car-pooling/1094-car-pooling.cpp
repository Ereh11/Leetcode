class Solution {
public:
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<pair<int, pair<int, int>>> join;
        int sum = 0;
        
        for(int i = 0 ; i < trips.size(); i++)
             join.push_back({trips[i][1], {trips[i][2], trips[i][0]}});
        
        sort(join.begin(), join.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
        
        for(int i = 0 ; i < join.size() ; i++) 
        {
            
             if(qu.empty()) 
                 sum += join[i].second.second, qu.push({join[i].second.first, join[i].second.second});
             else
             {
                 while(!qu.empty() && qu.top().first <= join[i].first)
                      sum -= qu.top().second, qu.pop();
                 
                 sum += join[i].second.second;
                 qu.push({join[i].second.first, join[i].second.second});
             }
           
            if(sum > capacity) return false;
        }
        
        return true;
    }
};