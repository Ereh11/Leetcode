class Solution {
public:
    double average(vector<int>& salary) {
        int mx = *max_element(salary.begin(), salary.end());
        int mn = *min_element(salary.begin(), salary.end()), su = 0;                           for(auto& it : salary) 
            su +=((it != mx && it != mn)? it:0);
                              
        return (su / double(salary.size() - 2));
    }
};