class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        vector<int> ump(26);
        ump['I'-65] =1, ump['V'-65] =5, ump['X'-65] =10, ump['L'-65] =50, ump['C'-65] =100;
        ump['D'-65] =500, ump['M'-65] =1000; 
        
        for(int i = 0; i < s.size() ; i++)
        {
            ans += ump[s[i] - 65];
            if(i > 0 && ump[s[i] - 65] > ump[s[i - 1] - 65]) ans -= 2 * ump[s[i - 1] - 65];
        }
        
        return ans;
    }
};