class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle) == haystack.npos) return -1;
        
        for(int i = 0 ; i < haystack.size() ; i++)
               if(i + needle.size() <= haystack.size() && haystack.substr(i, needle.size()) == needle)
                   return i;

        return -1;
    }
};