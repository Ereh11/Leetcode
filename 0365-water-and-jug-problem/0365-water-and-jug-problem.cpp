class Solution {
public:
    
    
    bool BFS(int &j1, int &j2, int &target)
    {
        int total = j1 + j2;
        vector<int> vis(1e6 + 1);
        queue<int> qu; 
        qu.push(0); vis[0] = 1;
        int operation[4] = {j1, -j1, j2, -j2};
        
        while(!qu.empty())
        {
            int ft = qu.front(); qu.pop();
            if(ft == target) return true;
            
            for(int i = 0 ; i < 4 ; i++) 
            {
                int nw = ft + operation[i];
                if(nw >= 0 && nw <= total && !vis[nw])
                    vis[nw] = 1, qu.push(nw);
            }
        }
        
        return false;
    }
    
    
    bool canMeasureWater(int cap1, int cap2, int targetCapacity) 
    {
        return BFS(cap1, cap2, targetCapacity);
    }
};



/*

*/