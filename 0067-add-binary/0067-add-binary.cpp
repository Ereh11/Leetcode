class Solution {
public:
    void rev(string &a){
        reverse(a.begin(), a.end());  
    }
    string addBinary(string a, string b) 
    {
        int sz = max(a.size(), b.size()), carry = 0;
        string res;
        
        rev(a), rev(b);
        while(a.size() < sz) a.push_back('0');
        while(b.size() < sz) b.push_back('0');
        rev(a), rev(b);
        
        for(int i = sz - 1; ~i ; i--)
        {
            if(a[i] == '1' && b[i] == '1' && carry) 
                carry +=((carry) ? 0 : 1), res.push_back('1');
            
            else if(a[i] == '1' && b[i] == '1' && !carry) 
                carry++, res.push_back('0');
            
            else if(a[i] == '0' && b[i] == '0' && carry) 
                carry--, res.push_back('1');
            
            else if(((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) && carry) 
                res.push_back('0');
            
            else if(((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) && !carry) 
                res.push_back('1');
            
            else if(a[i] == '0' && b[i] == '0' && !carry) 
                res.push_back('0');
        }
        
        if(carry) 
            res.push_back('1');
        
        rev(res);
        return res;
    }
};