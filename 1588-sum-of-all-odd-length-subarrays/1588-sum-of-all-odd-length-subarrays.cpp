class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
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
        
        return res;
    }
};