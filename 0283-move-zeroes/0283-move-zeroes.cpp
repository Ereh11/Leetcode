class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ansz = 0;

       for(auto it= nums.begin(); it != nums.end(); it++)
           if(!*it) nums.erase(it), it--, ansz++;

       for(int i = 0 ;i < ansz; i++) nums.push_back(0);
    }
};