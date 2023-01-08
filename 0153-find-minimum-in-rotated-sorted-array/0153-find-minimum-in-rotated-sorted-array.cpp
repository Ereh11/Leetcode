class Solution {
public:
    
    int findMin(vector<int>& v) 
    {
        int l = 0, r = v.size() - 1;
        
        while(l <= r)
        {
            int mid = ((l + r) >> 1);
            if(l + 1 == r || l == r) return min(v[l], v[r]);
            if(v[mid] > v[r]) l = mid;
            else r = mid;
        }
        
        return v[l];
    }
};


/*
*/