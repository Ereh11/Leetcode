class Solution {
public:
    int searchInsert(vector<int>& v, int t) {
        int st = 0, en = v.size() - 1;
        
        while(st <= en)
        {
            int mid = ((st + en) >> 1);
            if(v[mid] == t) return mid;
            else if(v[mid] > t) en = mid - 1;
            else st = mid + 1;
        }
        
        return st;
    }
};