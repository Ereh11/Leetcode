class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num); sort(s.begin(), s.end());
        return (int(s[0] - 48) * 10 + int(s[3] - 48)) + (int(s[1] - 48) * 10 + int(s[2] - 48));
    }
};