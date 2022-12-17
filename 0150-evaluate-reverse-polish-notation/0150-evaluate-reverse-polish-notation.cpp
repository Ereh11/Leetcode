class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> nums; int ans = 0;
        for(auto& it: tokens)
        {
            if(it != "+" && it != "-" && it != "*" && it != "/") nums.push(stoi(it));
            else
            {
                long long  b = nums.top(); nums.pop();
                long long a = nums.top(); nums.pop();
                if(it == "+") nums.push(a + b);
                else if(it == "-") nums.push(a - b);
                else if(it == "/") nums.push(a / b);
                else nums.push(a * b);
            }
        }
        return nums.top();
    }
};