class Solution {
public:
    int parent[27];
    int Find(int p)
    { 
        
        if(parent[p] == p) return p;
        return parent[p] = ((~parent[p]) ? Find(parent[p]) : p);
    }
    void Union(int p1, int p2)
    {
        p1 = Find(p1), p2 = Find(p2);
        parent[max(p1, p2)] = min(p1, p2);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        memset(parent, -1, sizeof(parent));
        
        for(int i = 0 ; i < s1.size(); i++)
            Union(s1[i] - 96, s2[i] - 96);
        
        for(int i = 0 ; i < baseStr.size(); i++)
            baseStr[i] = Find(baseStr[i] - 96) + 96;
        
        return baseStr;
    }
};