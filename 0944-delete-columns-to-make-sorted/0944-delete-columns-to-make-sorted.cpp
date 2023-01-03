class Solution {
public:
    int minDeletionSize(vector<string>& v) {
        int ans = 0;
        for(int i = 0 ; i < v.back().size() ; i++)
        {
            string s; 
            
            for(int j = 0 ; j < v.size() ; j++)  s.push_back(v[j].at(i));
            
            sort(s.begin(), s.end());
            
            for(int j = 0 ; j < v.size() ; j++) 
                if(v[j].at(i) != s[j]) { ans++;  break; }
            
        }
        
        return ans;
    }
};