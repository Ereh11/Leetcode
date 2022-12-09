class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans  = 0;
        for(int i = 0 ; i < mat.size(); i++) 
            ans +=(mat[i][i] + mat[i][mat.size() - i - 1]) - (i == mat.size() - i - 1 ? mat[i][i] : 0);
        
        return ans;
    }
};