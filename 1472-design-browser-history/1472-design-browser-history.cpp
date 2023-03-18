class BrowserHistory {
public:
     vector<string> vis;
    int stIndx, endIndx;
public:
    BrowserHistory(string homepage) {
        vis.push_back(homepage);
        stIndx = 0; 
        endIndx = 0;
    }
    
    void visit(string url) {
        stIndx += 1;
        if (vis.size() > stIndx) {
            vis[stIndx] = url;
        } 
        else {
            vis.push_back(url);
        }
       
        endIndx = stIndx;
    }
    
    string back(int steps) {
        stIndx = max(0, stIndx - steps);
        return vis[stIndx];
    }
    
    string forward(int steps) {
        stIndx = min(endIndx, stIndx + steps);
        return vis[stIndx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */