class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        vector<int> degree(n);
        unordered_set<int> edge[n];
        
        for(int i = 0 ; i < roads.size() ; i++)
        {
            degree[roads[i][0]]++, degree[roads[i][1]]++;
            edge[roads[i][0]].insert(roads[i][1]);
            edge[roads[i][1]].insert(roads[i][0]);
        }
        
        for(int i = 0 ; i < n ; i++)
            for(int j = i + 1; j < n; j++)
            {
                int sz = degree[i] + degree[j];
                if(edge[i].count(j) != 0) sz--;
                
                ans = max(ans, sz);
            }
        
        return ans;
            
    }
};