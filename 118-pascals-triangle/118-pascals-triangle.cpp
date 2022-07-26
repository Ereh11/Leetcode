class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(1), ans.push_back(temp); numRows--;
        if(numRows) temp.push_back(1), ans.push_back(temp), temp.clear(), numRows--;
        
        while(numRows)
        {
            temp.push_back(1);
            
            for(int j = 1 ; j < ans.back().size(); j++)
                temp.push_back(ans[ans.back().size()-1][j - 1] + ans[ans.back().size()-1][j]);
                
            temp.push_back(1);
            ans.push_back(temp), temp.clear(), numRows--;
        }
        return ans;
    }
};