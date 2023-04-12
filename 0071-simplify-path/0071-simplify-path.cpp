class Solution {
public:
    string simplifyPath(string path) 
    {
        stack<string> s;
        stringstream ss(path);
        string directory, res;
        
        while (getline(ss, directory, '/')) 
        {
            if (directory == "" || directory == ".") {
                continue;
            } 
            else if (directory == "..") 
            {
                if (!s.empty()) {
                    s.pop();
                }
            } 
            else {
                s.push(directory);
            }
        }
        
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
        
        return res.empty() ? "/" : res;
    }
};