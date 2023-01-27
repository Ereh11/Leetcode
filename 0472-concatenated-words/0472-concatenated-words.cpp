class Solution {
public:
    int solve(set<string>&st, string& word, int start)
    {
        if (start >= word.size()) return 0;

        string strTillPivot = "";
        int mx = INT_MIN;
        
        for (int pivotIdx = start; pivotIdx < word.size(); pivotIdx++)
        {
            strTillPivot.push_back(word[pivotIdx]);
            if (st.find(strTillPivot) == st.end()) continue;
            int nextPartitionCount = solve(st, word, pivotIdx + 1);
            if (nextPartitionCount == INT_MIN) continue;
            int totalPartitions = 1 + nextPartitionCount;
            mx = max(mx, totalPartitions);
        }
        
        return mx;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        set<string>st;
        for (string& word : words) st.insert(word);
        vector<string>ans;
        for (string word : words) {
            int partitionCount = solve(st, word, 0);
            if (partitionCount >= 2) ans.push_back(word); 
        }
        return ans;
        
    }
};