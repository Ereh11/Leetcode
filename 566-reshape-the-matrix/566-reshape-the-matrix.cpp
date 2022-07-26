class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> matrixReshape;
	    matrixReshape.resize(r, vector<int>(c));
        int row = 0, col = 0;
        if(r*c!=mat.size()* mat[0].size()) return mat;
        for(int i = 0 ;i < mat.size(); i++)
            for(int j = 0 ; j < mat[0].size(); j++)
            {
                if(col == c) col = 0, row++;
                matrixReshape[row][col++] = mat[i][j];
            }
    return matrixReshape;
                
    }
};