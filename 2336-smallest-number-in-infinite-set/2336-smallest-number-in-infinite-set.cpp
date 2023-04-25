class SmallestInfiniteSet {
    set<int> st;
    int cnt;
public:
    SmallestInfiniteSet() {
       cnt = 1;
    }
    int popSmallest() {
        int ans;
        
        if (!st.empty()) {
            ans = *st.begin();
            st.erase(st.begin());
        } 
        else {
            ans = cnt;
            cnt += 1;
        }
        return ans;
    }
    void addBack(int num) {
        if (cnt <= num || st.find(num) != st.end()) {
            return;
        }
        st.insert(num);
    }
};