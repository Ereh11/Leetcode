class Solution {
public:
    
    vector<int> edge[100001];
    int BFS(int &headID, vector<int>& time)
    {
        int mx = 0;
        queue<pair<int, int>> qu; qu.push({headID, 0});
        
        while(!qu.empty())
        {
            int sz = qu.size();
            while(sz--)
            {
                int ft = qu.front().first;
                int timetake = qu.front().second;
                qu.pop();
                
                int current = timetake + time[ft];
                mx = max(mx, current);
                
                for(auto& child: edge[ft])
                    qu.push({child, current});
                
            }
        }
        
        return mx;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        for(int i = 0; i < n; i++)
            if(~manager[i])  edge[manager[i]].push_back(i);
            
        return BFS(headID, informTime);
    }
};