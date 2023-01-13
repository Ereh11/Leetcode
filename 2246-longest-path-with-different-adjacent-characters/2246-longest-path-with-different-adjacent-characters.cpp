class Solution {
public:
    vector<int> edge[100001];
    int ans = 1;
    int DFS(string &s, int node)
    {
        int mx1 = 0, mx2 =0, len;
        if(edge[node].empty()) return 1;
        for(auto &child : edge[node])
        {
        
            len = DFS(s, child); ans = max(ans, len);
            if(s[node] != s[child])
            {
                if(len > mx1)   
                    mx2 = mx1,mx1 = len;
                else 
                    mx2 = max(mx2 , len);
            }
        }
    
        ans = max(ans, (mx1 + mx2) + 1);
    
        return ++mx1;
    }
    int longestPath(vector<int>& parent, string s)
    {
        for(int i = 1; i < parent.size(); i++) 
            edge[parent[i]].push_back(i);
        
        DFS(s, 0);
        
        return ans;
    }
};