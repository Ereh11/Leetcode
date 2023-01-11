class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char target) {
        
        int l = 0, r = v.size(), indx = 0;
        while(l <= r)
        {
            int mid = ((l + r) >> 1);
            if(l == v.size()) return v[0];
            if(v[mid] > target)  r = mid - 1;
            else  l = mid + 1;
        }
        return v[l];
    }
};