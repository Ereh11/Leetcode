class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        int cnt = 0, sz = v.size();
        
        for(int i = 0 ; i < sz; i++)
        {
            if(!v[i]) 
            {
                if((sz == 1) || (!i && !v[i + 1])|| 
                   (i + 1 == sz && !v[i - 1]) || 
                   (i > 0 && i + 1 < sz && !v[i - 1] && !v[i + 1]))
                {
                    cnt++, v[i] = 1, i++;
                }
            }
        }
        
        return cnt >= n;
    }
};