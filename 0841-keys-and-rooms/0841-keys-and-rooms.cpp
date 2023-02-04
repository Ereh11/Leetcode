class Solution {
public:
    vector<int> edge[1000], vis;
    void DFS(int node)
    {
        vis[node] = 1;
        for(auto& child: edge[node])
            if(!vis[child]) DFS(child);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vis.resize(n);
        for(int i = 0; i < n ;i++)
            for(auto& col: rooms[i]) edge[i].push_back(col);
        
        DFS(0);
        for(int i = 0; i < rooms.size() ;i++)
            if(!vis[i]) return false;
        
        return true;
    }
};


/*

*/