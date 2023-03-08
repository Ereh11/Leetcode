class Solution {
public:
    bool BS(vector<int>& piles, int &h, int &Assuming_speed)
    {
        long long ans = 0;
        
        for(auto& it: piles) {
            ans +=ceil(it / double(Assuming_speed));
        }
        
        return ans <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1, r = 1e9, Assuming_speed = 0, ans = 0;
        
        while(l <= r)
        {
            Assuming_speed = ((l + r) >> 1);
            if(BS(piles, h, Assuming_speed))
                ans = Assuming_speed, r = Assuming_speed - 1;
            else
                l = Assuming_speed + 1;
        }
        
        return ans;
    }
};