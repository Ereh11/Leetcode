class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq; 
        int mn = INT_MAX, ans = INT_MAX;
        for(auto& it: nums)
        {
            if(it & 1)
                pq.push(it * 2), mn = min(mn, it * 2);
            else
                pq.push(it), mn = min(mn, it);
        }
        
       
        while(!pq.empty())
        {
            int tp = pq.top();
            pq.pop();
            ans = min(ans,tp - mn);
            
            if((tp & 1)) break;
            
            mn = min(mn, tp / 2);
            pq.push(tp / 2);
        } 
        
        return ans;
    }
};