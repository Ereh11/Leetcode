class NumArray {
private:
    vector<int> ans;
public:
    NumArray(vector<int>& nums) {
        ans = nums;
        for(int i = 1 ; i < ans.size(); i++) ans[i] += ans[i - 1];
    }
    
    int sumRange(int left, int right) {
        return ((left) ? ans[right] - ans[left - 1] : ans[right] );
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */