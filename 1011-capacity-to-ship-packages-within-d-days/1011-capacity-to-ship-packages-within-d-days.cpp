class Solution {
public:
    bool BS(vector<int>& weights, int capacity, int &days)
    {
        int requireDays = 1, sum = 0;
        for(auto& it: weights)
        {
            sum += it;
            if(sum > capacity)
                requireDays++, sum = it;
        }
        
        return requireDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0, mx = 0;
        for(auto& it: weights)
            sum +=it, mx = max(mx, it);
        
        int l = mx, r = sum, mid = 0;
        
        while(l <= r)
        {
            mid = ((l + r) >> 1);
            if(BS(weights, mid, days)) r = mid - 1;
            else l = mid + 1;
        }
        
        return l;
    }
};