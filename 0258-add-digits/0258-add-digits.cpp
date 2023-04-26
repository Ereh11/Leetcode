class Solution {
public:
    int addDigits(int num) {
        if(!num)
            return 0;
        else if(num % 9 == 0)
            return 9;
        
        return num % 9;
    }
};