class SubrectangleQueries {
    private: 
    vector<vector<int>> ans;
    
    public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        swap(ans, rectangle);
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = min(row1, row2); i <=  max(row1, row2); i++)
            for(int j = min(col1, col2); j <=  max(col1, col2); j++) 
                ans[i][j] = newValue;
    }
    
    int getValue(int row, int col) {
        return ans[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */