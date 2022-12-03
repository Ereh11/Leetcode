class Solution {
public:
    int countOdds(int low, int high) {
        return ceil(high / 2.0) - ceil(low / 2.0) + (low & 1);
    }
};