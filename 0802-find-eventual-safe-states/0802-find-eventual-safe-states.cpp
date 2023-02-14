class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> edge[n], ans, safenode(n), outcome(n);
        queue<int> qu;
        
        for(int i = 0; i < n; i++)
        {
            for(auto& it: graph[i])  edge[it].push_back(i);
            
            outcome[i] = graph[i].size();
            if(!outcome[i]) qu.push(i);
        }
        
        while(!qu.empty())
        {
            int ft = qu.front();
            qu.pop();
            safenode[ft] = 1;
            
            for(auto& it: edge[ft])
                if(--outcome[it] == 0) qu.push(it);
        }
        for(int i = 0 ; i < n ; i++)
            if(safenode[i]) ans.push_back(i);
        
        return ans;
    }
};





/*
*/