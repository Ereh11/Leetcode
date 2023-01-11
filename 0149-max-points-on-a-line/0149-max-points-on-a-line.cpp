class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        if(n < 3) return n;


        for(int i=0; i < n;i++)
        {
            unordered_map<double,int> ump;
            int cnt = 1;
            for(int j=i+1;j<n;j++)
            {
                if(points[i][0] == points[j][0] && points[j][1] == points[i][1]) cnt++;
                else if(points[i][0] == points[j][0])  ump[INT_MAX]++;
                else
                {
                    double slope = double(points[i][1]-points[j][1]) / double(points[i][0]-points[j][0]);
                    ump[slope]++;
                }
            }
            
            int mx = 0;
            for(auto &it : ump) mx = max(mx, it.second);
            
            ans = max(ans, mx + cnt);
        }
        return ans;
    }
};