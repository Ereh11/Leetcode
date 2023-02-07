class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> ump;
        int p1 = 0, p2 = 0, n = fruits.size(), ans = 0;
        
        while(p2 < n)
        {
            ump[fruits[p2]]++;
            
            while(ump.size() > 2) 
            {
                ump[fruits[p1]]--;
                if(ump[fruits[p1]] == 0) ump.erase(fruits[p1]);
                p1++;
            }
            
            ans = max(ans, p2 - p1 + 1);
            p2++;
        }
        
        return ans;
    }
};


/*
*/