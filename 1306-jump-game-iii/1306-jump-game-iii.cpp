class Solution {
public:
    bool BFS(vector<int>& arr, int start)
    {
        vector<int> vis(5 * 1e4 + 1);
        queue<int> qu; qu.push(start);
        
        while(!qu.empty())
        {
            int ft = qu.front(); qu.pop();
            if(!arr[ft]) return true;
            int rht = ft + arr[ft], lf = ft - arr[ft];
            
            if(rht >= 0 && rht < arr.size() && !vis[rht])
                vis[rht] = 1, qu.push(rht);
            if(lf >= 0 &&  lf < arr.size() && !vis[lf])
                vis[lf] = 1, qu.push(lf);
        }
        
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        return BFS(arr, start);
    }
};