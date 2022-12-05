class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = 3 * 1e4, indx = -1;
        for(int i = 0 ; i < points.size() ; i++)
                if((points[i][0] == x || points[i][1] == y)) 
                {
                    if(abs(points[i][0] - x) + abs(y - points[i][1]) < ans)
                        indx = i, ans = abs(points[i][0] - x) + abs(y - points[i][1]);
                }
            
        
        return indx;
    }
};