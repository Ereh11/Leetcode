class Solution {
public:
    int indx = 0;
    void reverseString(vector<char>& s) 
    {
        if(indx == s.size()/2) return;
        
        swap(s[indx], s[s.size() - indx - 1]);
        indx++;
        
        reverseString(s);
    }
};