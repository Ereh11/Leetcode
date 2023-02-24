class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> temp;
        for(int i=0;i<capital.size();i++)   
            temp.push_back({capital[i] , profits[i]});

        sort(temp.begin() , temp.end());
        priority_queue<int> pq;

        int indx = 0;
        while(indx < temp.size() && temp[indx].first <= w)  
            pq.push(temp[indx++].second);
        
        while(!pq.empty() && k--)
        {
            int curr = pq.top();
            pq.pop();
            w += curr;
            while(indx < temp.size() && temp[indx].first <= w)  
                pq.push(temp[indx++].second);
        }
        
        return w;
    }
};