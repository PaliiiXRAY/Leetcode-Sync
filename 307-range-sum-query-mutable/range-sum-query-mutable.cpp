class NumArray {
    vector<int> arr;
    vector<int> seg;
    int n;
    void build(int ind, int low, int high) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid + 1, high);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r) {
        // completely overlap
        if (low >= l and high <= r) {
            return seg[ind];
        }
        // completely outside
        if (high < l or low > r)
            return 0;
        // partial overlap
        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }

    void updatetree(int ind, int low, int high, int pos, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (pos <= mid) {
            updatetree(2 * ind + 1, low, mid, pos, val);
        } else {
            updatetree(2 * ind + 2, mid + 1, high, pos, val);
        }
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

public:
    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        if (n > 0) {
            seg.resize(4 * n);
            build(0, 0, n - 1);
        }
    }

    void update(int index, int val) {
        arr[index] = val;
        updatetree(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */