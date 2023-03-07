class Solution {
public:
    int hammingDistance(int x, int y) {
        string _x = bitset<32>(x).to_string();
        string _y = bitset<32>(y).to_string();
        int ans = 0;
        
        for(int i =0 ; i < _x.size() ; i++) {
            ans += (_x[i] != _y[i]);
        }
        
        return ans;
    }
};