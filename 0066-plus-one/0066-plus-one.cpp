class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size();
        for(int i = sz - 1 ; ~i ; i--)
        {
            if(digits[i] < 9) {
               digits[i]++;
               break;
            }
            else  {
                digits[i] = 0;
            }
            
            if(i == 0) {
                digits.resize(sz + 1);
                
                for(int i = sz - 1 ; ~i ; i--)
                    swap(digits[i], digits[i + 1]);
                
                digits[0] = 1;
            }
                
        }
        
        return digits;
    }
};