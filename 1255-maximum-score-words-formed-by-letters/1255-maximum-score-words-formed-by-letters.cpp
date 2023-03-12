class Solution {
public:
    bool vis[15];
    int ans = 0, mx = 0;
    void solve(vector<string>& words, int indx, vector<int>& score, vector<int>& frq)
    {
        //if(indx == words.size()) return;
        
        for(int i = indx ; i < words.size() ; i++)
        {
            bool isExist = 1;
            int calcuScore = 0;
            
            for(auto& it: words[i])  {
                isExist &= (frq[it - 'a'] != 0), calcuScore += score[it - 'a'];
                frq[it - 'a']--;
            }
            //cout<< words[i] << " " << isExist <<" "<<calcuScore<<"\n";
            if(!vis[i] && isExist)
            {
                vis[i] = 1;
                ans += calcuScore;
                mx = max(mx, ans);
                
                solve(words, i + 1, score, frq);
                
                vis[i] = 0;
                ans -= calcuScore;
            }
            
            for(auto& it: words[i])  frq[it - 'a']++;
        }
    }
    
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> frq(27);
        
        for(auto& it: letters) frq[it - 'a']++;
        
        solve(words, 0, score, frq);
        
        return mx;
    }
};