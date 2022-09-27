class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
	    sort(intervals.begin(), intervals.end());

	    for (int i = 0; i < intervals.size() - 1; i++)
		    if (intervals[i + 1][0] <= intervals[i][1]) {
			    intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
			    intervals[i][0] = -1;
            }
	
	   for (auto& it : intervals) 
           if (~it.at(0)) ans.push_back({it.at(0), it.at(1)});
    
        return ans;
    }
};