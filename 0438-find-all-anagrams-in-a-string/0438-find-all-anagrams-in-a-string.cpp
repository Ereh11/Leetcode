class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length(), i = 0, j = 0;
	
        if(m > n) return {};
	    vector<int> v1(26,0), v2(26,0), res;
    
        for(int l = 0 ; l < m ; l++) v1[p[l]-'a']++;
    
        while(j < n)
        {
            v2[s[j]-'a']++;
		    if((j-i+1) < m)  j++;
            else if((j-i+1)==m)
            {               
                if(v1 == v2) res.push_back(i);
                v2[s[i]-'a']--,i++, j++;
            }
        }
    
        return res;
    }
};