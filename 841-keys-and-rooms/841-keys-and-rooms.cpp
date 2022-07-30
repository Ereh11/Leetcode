class Solution {
public:
    vector<bool> vis;
    void DFS(int node, vector<vector<int>>& rooms)
    {
	    vis[node] = 1;
	    for (auto& it : rooms[node])
		    if (!vis[it]) DFS(it, rooms);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        vis.resize(rooms.size());
        DFS(0, rooms);
        
        for(int i = 0 ; i < rooms.size() ; i++)
            for(int j = 0 ; j < rooms[i].size() ; j++) 
                if(!vis[rooms[i][j]]) return false;
        
        return true;
    }
};