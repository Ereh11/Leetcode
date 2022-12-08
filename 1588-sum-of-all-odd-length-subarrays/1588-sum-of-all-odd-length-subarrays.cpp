class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& a) {
        /*
        O(N)
        int res = 0;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            int temp = 0, cnt = 0;
            for(int j = i; j < arr.size(); j++)
            {
                temp += arr[j], cnt++;
                if(cnt & 1) res += temp;
            }
        }
        
        return res;*/
        
        int res = 0;
        for(int i = 0 ; i < a.size(); i++)
            res += a[i] * ceil(((i + 1) * (a.size() - i)) / 2.0);
        
        return res;
    }
};