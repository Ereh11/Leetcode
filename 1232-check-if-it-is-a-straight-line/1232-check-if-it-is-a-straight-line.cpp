class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& x) {
        if(x.size() == 2) return 1;
        
        for(int i = 2 ; i < x.size() ; i++)
            if(((x[i - 1][0] -  x[i - 2][0])*(x[i][1] -  x[i - 2][1])) - ((x[i - 1][1] -  x[i - 2][1])*(x[i][0] -  x[i - 2][0])) != 0) return 0;
        
        return 1;
    }
   // (x2−x1)(y3−y1)−(y2−y1)(x3−x1)=0
};