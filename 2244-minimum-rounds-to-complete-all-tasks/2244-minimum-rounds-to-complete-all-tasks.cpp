class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        set<int> se;
        int ans = 0;
        map<int, int> mp;
        for(auto& it: tasks) se.insert(it), mp[it]++;
        
        for(auto& it: se){
            while(1) 
            {
                if(mp[it] == 1) return -1;
                else if(!mp[it]) break;
                else if(mp[it] % 3 == 0 || mp[it] & 1) mp[it] -=3, ans++;
                else mp[it] -=2, ans++;
            }
        }
        return ans;
    }
};