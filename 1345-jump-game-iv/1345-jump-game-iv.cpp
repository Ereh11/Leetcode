class Solution {
public:
    
    int BFS(vector<int>& arr)
    {
        unordered_map<int, vector<int>> ump;
        for(int i = 0 ; i < arr.size() ; i++)
            ump[arr[i]].push_back(i);
        
        queue<int> qu; 
        vector<bool> vis(50001, 0); 
        qu.push(0), vis[0] = 1;
        int ans = 0, n = arr.size();
        
        while(!qu.empty())
        {
            int sz = qu.size();
            while(sz--)
            {
                int ft = qu.front();   qu.pop();
                
                if(ft == n - 1) return ans;
                
                if(ft - 1 >= 0 && !vis[ft - 1])
                    qu.push(ft - 1), vis[ft - 1] = 1;
                
                if(ft + 1 < n && !vis[ft + 1])
                    qu.push(ft + 1), vis[ft + 1] = 1;
                
                if(!ump[arr[ft]].empty()) 
                {
                    for(auto& it: ump[arr[ft]])  {
                         if(!vis[it])
                             qu.push(it), vis[it] = 1;
                    }
                    ump[arr[ft]].clear();
                }
            }
            
            ans++;
        }
        
        return ans;
    }
    
    int minJumps(vector<int>& arr) 
    {
        return BFS(arr);
    }
};


