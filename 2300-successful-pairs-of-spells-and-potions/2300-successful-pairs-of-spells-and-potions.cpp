class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(), potions.end(), greater<int>());
        vector<int> ans;
        
        for(auto& it: spells) {
            
            int l = 0 , r = potions.size() - 1, mid = 0, cnt = 0;
            while(l <= r)
            {
                mid = ((l + r) >> 1);
                
                if((long long)potions[mid] * it >= success)
                    cnt = mid + 1, l = mid + 1;
                else
                    r = mid - 1;
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};