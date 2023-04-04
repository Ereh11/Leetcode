class Solution {
public:
    int partitionString(string s) {
        vector<bool> frq(27);
        int ans = 1, i  = 0;
        
        while(i < s.size() )
        {
          
           if(frq[s[i] - 97])
           {
               ans++;
               frq = vector<bool> (27);
           }
            
           frq[s[i] - 97] = 1;
           i++;
        }
        
        return ans;
    }
};