class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto& it: matrix)
            for(auto& e: it) 
                if(e == target) return true;
        return false;
    }
};