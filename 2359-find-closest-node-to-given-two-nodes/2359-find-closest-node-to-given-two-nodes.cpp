class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& distance, vector<bool>& vis){
        vis[node] = true;
        int neighbor = edges[node];
        if (neighbor != -1 && !vis[neighbor]) {
            distance[neighbor] = distance[node] + 1;
            dfs(neighbor, edges, distance, vis);
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size(), ans = -1, minDist = INT_MAX;
        vector<int> dist1(n, 0), dist2(n, 0);
        vector<bool> vis1(n, false), vis2(n, false);
        dfs(node1, edges, dist1, vis1);
        dfs(node2, edges, dist2, vis2);

        for(int currNode = 0; currNode < n; currNode++)
            if(vis1[currNode] == true && vis2[currNode] == true && minDist > max(dist1[currNode], dist2[currNode]))
            {
                minDist = max(dist1[currNode], dist2[currNode]);
                ans = currNode;
            }
        return ans;
    }
};