class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int indx = 0, n = arr.size();

        
        while (indx + 1 < n && arr[indx] < arr[indx + 1])
            indx++;

        if (indx == 0 || indx == n - 1)
            return false;

        while (indx + 1 < n && arr[indx] > arr[indx + 1])
            indx++;

        return (indx == n - 1);
    }
};