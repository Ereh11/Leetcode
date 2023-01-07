class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = 0, totalcost = 0, validindx = 0, check = 0;
        for(int i = 0 ; i < gas.size()  ; i++)
        {
            totalgas += gas[i], totalcost += cost[i];
            check += gas[i] - cost[i];
            if(check < 0) 
                validindx = i + 1, check  = 0;
        }
        
        return (totalcost > totalgas ? -1 : validindx);
    }
};