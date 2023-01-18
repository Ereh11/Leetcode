class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        
        int l = 0, r = v.size() - 1;
        while(l <= r)
        {
            int mid = ((l + r) >> 1);
            if(v[mid] > v[mid + 1]) r = mid - 1;
            else l = mid + 1;
        }
        
        return l;
    }
};