class Solution {
public:
    int heightChecker(vector<int>& heights) {
         vector<int> expect = heights;
         int ans = 0;
         sort(expect.begin(), expect.end());
        
         for(int i = 0 ; i < heights.size() ; i++)
             ans +=(heights[i] != expect[i]);
         
         return ans;
    }
};