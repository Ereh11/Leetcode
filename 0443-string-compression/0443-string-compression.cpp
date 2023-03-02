class Solution {
public:
    int compress(vector<char>& s) {
        int indx = 0, n = s.size(), sz = 1;
        string tp; 
        for(int i = 0 ; i < n ; i++)
        {
            if(i + 1 < n && s[i] == s[i + 1]) sz++;
            
            if((i + 1 < n && s[i] != s[i + 1]) || i == n - 1)
            {
                s[indx++] = s[i];
                if(sz > 1) 
                {
                    int indxForTp = 0;
                    tp = to_string(sz);
                    sz = 1;
                    
                    while(indxForTp < tp.size() && indxForTp < n)
                            s[indx++] = tp[indxForTp++];
                    while(indxForTp < tp.size())
                            s.push_back(tp[indxForTp++]);
                }
            }
        }
        
        while(indx < s.size()) 
            s.pop_back();
        
        return s.size();
    }
};