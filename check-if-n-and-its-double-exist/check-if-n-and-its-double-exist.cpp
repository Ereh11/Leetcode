class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        unordered_map<int, int> frq;
        for(auto& it: arr)  frq[it]++;
        
        for(auto& it: arr)
        {
            if(!it && frq[it] > 1) return true;
            
            else if(it && frq[it * 2]) return true;
        
        }
        
        return false;
    }
};