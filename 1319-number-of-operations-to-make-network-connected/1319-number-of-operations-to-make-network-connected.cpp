class Solution {
public:
    vector<int> parent;
    int find(int node) {
        return (node == parent[node] ? node: find(parent[node]));
    }
    void Union(int node1, int node2) {
        int p1 = find(node1), p2 = find(node2);
        parent[p1] = p2;
    }
    
    
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        parent.resize(n);
        int cnt = 0, ans = 0;
        for(int i = 0 ; i < n ; i++) parent[i] = i;
        
        for(int i = 0 ; i < connections.size(); i++)
        {
            if(find(connections[i][0]) != find(connections[i][1])) 
                Union(connections[i][0], connections[i][1]);
            else  cnt++;
        }
                
        
        for(int i = 1; i < n ; i++)
            if(find(i) != find(i - 1)) Union(i, i - 1), cnt--, ans++;
        
        return ((cnt >= 0) ? ans : -1);
    }
};