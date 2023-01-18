class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        for(int i = 0 ; i < arr.size(); i++)
        {
            int l = 0, r = arr.size() - 1;
            while(l <= r)
            {
                 int mid = ((l + r) >> 1);
                 if(arr[mid] == arr[i] * 2 && i != mid) return true;
                 if(arr[mid] < arr[i] * 2) l = mid + 1;
                 else r = mid - 1;
            }
      }
        return false;
    }
};