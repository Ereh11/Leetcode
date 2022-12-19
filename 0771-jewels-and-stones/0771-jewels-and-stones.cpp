class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int> frq(123); int ans = 0;
        for(auto& it: jewels) frq[it] = 1;
        for(auto& it: stones) ans +=(frq[it] > 0);
        
        return ans;
    }
};