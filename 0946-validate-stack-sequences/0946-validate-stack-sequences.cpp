class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int indxPush = 0, indxPop = 0;
        stack<int> st;
        
        while(indxPop < popped.size())
        {
            if(st.empty())
                st.push(pushed[indxPush++]);
            else if(popped[indxPop] == st.top())
                    st.pop(), indxPop++;
            else if(indxPush < pushed.size())
                st.push(pushed[indxPush++]);
            else
                return false;
        }
        
        return true;
    }
};