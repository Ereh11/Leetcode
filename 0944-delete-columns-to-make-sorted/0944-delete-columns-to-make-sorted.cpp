class Solution {
public:
    int minDeletionSize(vector<string>& v) {
        int ans = 0;
        for(int i = 0 ; i < v.back().size() ; i++)
            for(int j = 1 ; j < v.size(); j ++)
                if(v[j][i] < v[j - 1][i]){ ans++; break; }
        
        return ans;
    }
};