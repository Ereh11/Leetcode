class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        queue<string> queue;
        unordered_set<string> st;
        queue.push(startGene);
        st.insert(startGene);
        
        int levels = 0;
        while (!queue.empty()) 
        {
            int nodesInQueue = queue.size();
            
            for (int j = 0; j < nodesInQueue; j++) 
            {
                string node = queue.front();
                queue.pop();

                if (node == endGene)
                    return levels;
                
                for (auto& it: "ACGT") 
                {
                    for (int i = 0; i < node.size(); i++) 
                    {
                        string neighbor = node;
                        neighbor[i] = it;
                        if (!st.count(neighbor) && find(bank.begin(), bank.end(), neighbor) != bank.end()) {
                            queue.push(neighbor);
                            st.insert(neighbor);
                        }
                    }
                }
            }
            
            levels++;
        }
        
        return -1;
    }    
};