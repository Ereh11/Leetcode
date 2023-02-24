class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        stack<int> st;
        for(auto& it: operations)
        {
            if(it != "C" && it != "+" && it != "D")
                st.push(stoi(it));
            else
            {
                if(it == "C") 
                    st.pop();
                else if(it == "D")
                    st.push(st.top() * 2);
                else {
                    int tp1 = st.top(); st.pop();
                    int tp2 = st.top(); st.pop();
                    st.push(tp2), st.push(tp1);
                    st.push(tp1 + tp2);
                }
            }
        }
        
        int sum = 0;
        
        while(!st.empty())
            sum += st.top(), st.pop();
    
        return sum;
    }
};