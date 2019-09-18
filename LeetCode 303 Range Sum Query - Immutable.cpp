// LeetCode 303 Range Sum Query - Immutable.cpp

class NumArray {
public:
    NumArray(vector<int> nums) : sum(nums.size() + 1) {
        for (int i = 1; i < sum.size(); i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
    
private:
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */