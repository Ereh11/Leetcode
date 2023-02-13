class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) 
    {
      unordered_map<int, bool> vis;
      int mx = 0, ans = 0;

      for (auto& it : forbidden)
            vis[it] = 1, mx = max(mx, it);

      mx = a + b + max(mx, x);
      queue<pair<int, bool>> qu;
      qu.push({0, 1}), vis[0] = 1;

      while (!qu.empty())
        {
            int sz=qu.size();
	        while (sz--)
	        {
		        int val = qu.front().first;
		        bool canback = qu.front().second;
		        qu.pop();
		
		        if (val == x) return ans;
		        int back = val - b, forward = val + a;

		        if (canback && back >= 0 && !vis[back])
			        qu.push({back, false}), vis[back] = true;
		
	            if (forward <= mx && !vis[forward])
		            qu.push({forward, true}), vis[forward] = true;
		
	        }
	
	        ans++;
        }

        return -1;
    }
};