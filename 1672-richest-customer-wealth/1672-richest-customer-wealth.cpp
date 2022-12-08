class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for(auto& r: accounts)
        {
            int w = 0;
            for(auto& c: r) w +=c;
            res = max(res, w);
        }
               
        return res;
    }
};