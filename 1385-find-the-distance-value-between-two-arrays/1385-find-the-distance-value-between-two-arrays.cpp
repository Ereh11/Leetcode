class Solution {
public:
    int findTheDistanceValue(vector<int>& a1, vector<int>& a2, int d) {
        sort(a2.begin(), a2.end());
        int ans = 0;
        for(auto &it: a1)
        {
            int l = 0, r = a2.size() - 1; bool b = 1;
            while(l <= r)
            {
                int mid = ((l + r) >> 1);
                if(abs(it - a2[mid]) <= d) {b = 0; break; }
                if(a2[mid] > it) r = mid - 1;
                else l = mid + 1;
                
            }
            ans += b;
        }
        
        return ans;
    }
};

/*
*/