class Solution {
public:
    vector<int> frqs1, frqs2;
    bool check()
    {
        for(int i = 0 ; i < 26 ; i++)
                if(frqs1[i] != frqs2[i]) return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
       
        int n = s1.size(), m = s2.size();
        if(n > m) return false;
        
        frqs1.resize(26, 0), frqs2.resize(26, 0);
        
        for(int i = 0; i < n ;i++)
            frqs1[s1[i] - 'a']++, frqs2[s2[i] - 'a']++;
        
        if(check()) return true;
        for(int i = n; i < m ;i++)
        {
            frqs2[s2[i] - 'a']++, frqs2[s2[i - n] - 'a']--;
            if(check()) return true;
        }
        
        return false;
    }
};