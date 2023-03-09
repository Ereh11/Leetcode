class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size() - 1, mx = arr[n];
        arr[n] = -1;
        for(int i = n - 1 ; ~i ; --i){
            int tp = arr[i];
            arr[i] = mx;
            mx = max(mx, tp);
        }
        
        return arr;
    }
};