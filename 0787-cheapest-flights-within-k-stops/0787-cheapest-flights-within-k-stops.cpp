class Solution {
public:
    vector<pair<int, int>> edge[101];
    int BFS(int src, int dst, int k)
    {
        queue<pair<int, int>> qu;
        qu.push({src, 0});
        int step = 0;
        vector<int> cost(101, INT_MAX);
        while(step <= k && !qu.empty())
        {
            int sz = qu.size();
            while(sz--)
            {
                auto nw = qu.front(); 
                qu.pop();
                for(auto& it: edge[nw.first])
                    if(it.second + nw.second < cost[it.first])
                    {
                        cost[it.first] = it.second + nw.second;
                        qu.push({it.first, cost[it.first]}); 
                    }
            }
            step++;
        }
        
        return ((cost[dst] == INT_MAX) ? -1 : cost[dst]);
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(auto& it: flights) 
            edge[it[0]].push_back({it[1], it[2]});
        return BFS(src, dst, k);
    }
};
/*
*/