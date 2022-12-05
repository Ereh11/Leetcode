class Solution {
public:
    int subtractProductAndSum(int n) {
        int mul = 1, su = 0;
        while(n)
            mul *= (n % 10), su += (n % 10), n /=10;
        
        return mul - su;
    }
};