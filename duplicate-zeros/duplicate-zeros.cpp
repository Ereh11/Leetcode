class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(), sz = n - 1, possibleDeletion = 0;
        bool backZero = 0;
        for(int i = 0; i <= sz; i++)
        {
            
            if(!arr[i] && i != sz)   sz--;
            else if(!arr[i] && i == sz)  backZero = 1;
            
            
        }
        
        int indx = n - 1, indxVal = sz;
        bool twice = 1;
        
        while(indxVal >= 0 && indx >= 0)
        {
            
            arr[indx--] = arr[indxVal];
            
            if(!arr[indxVal] && twice && !backZero)
                twice = 0;
            else
                indxVal--, twice = 1, sz--;
            
            if(backZero) backZero = 0;
            
        }
    }
};