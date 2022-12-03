class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        
        for(auto& it: address)
            if(it!='.') ans.push_back(it);
            else
                ans.push_back('['), ans.push_back('.'), ans.push_back(']');
        
        return ans;
    }
};