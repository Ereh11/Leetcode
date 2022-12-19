class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(auto &it: sentences)
        {
            int cnt = 0;
            for(int i = 0 ; i<it.size(); i++)
                if(it[i] == 32 || i == it.size() - 1) cnt++;
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};