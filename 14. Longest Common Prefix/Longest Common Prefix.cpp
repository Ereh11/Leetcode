class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) 
            return strs[0];
        
        string pfx = strs[0];
        for(int i = 1; i < strs.size(); i++)
        {
            string Now = strs[i];

            if(pfx.empty() || Now.empty())
                return "";

            pfx = pfx.substr(0, min(Now.size(), pfx.size()));
            for(int indx = 0; indx < pfx.size(); indx++)
            {
                if(pfx[indx]!= Now[indx]) {
                        pfx = pfx.substr(0, indx);
                        break;
                    }
            }
        }

        return pfx;
    }
};