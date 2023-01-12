class Solution {
public:
    vector<int> ans;
    void DFS(int node, int parent, vector<int>& count, vector<int> adj[], string &labels)
    {
        for(auto &i:adj[node])
        {
            if(i != parent)
            {
                vector<int> temp(26, 0);
                
                DFS(i, node, temp, adj, labels);
                for(int i= 0; i < 26 ;i++) count[i] +=temp[i];
            }
        }
        count[labels[node]-'a']++;
        ans[node]=count[labels[node]-'a'];
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        vector<int> adj[n];
        for(auto &it: edges)
            adj[it[0]].push_back(it[1]), adj[it[1]].push_back(it[0]);
        
        ans.resize(n,0);
        vector<int> count(26,0);
        DFS(0, -1, count, adj, labels);
        return ans;
    }
};