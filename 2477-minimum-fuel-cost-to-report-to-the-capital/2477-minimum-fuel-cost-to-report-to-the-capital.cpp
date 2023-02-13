class Solution {
public:
    long long ans;
    vector<int> edge[100000];
    long long DFS(int node, int parent, int& seats) 
    {
       
        int cnt = 1;
        for (auto& child : edge[node]) {
            if (child != parent) 
                cnt += DFS(child, node, seats);
        }

        if (node != 0) 
            ans += ceil((double)cnt / seats);
        
        return cnt;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        
        for (auto& road : roads) {
            edge[road[0]].push_back(road[1]);
            edge[road[1]].push_back(road[0]);
        }
        
        DFS(0, -1, seats);
        
        return ans;
    }
};