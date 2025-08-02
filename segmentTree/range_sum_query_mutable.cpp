class NumArray {
public:
    vector<int> segTree;
    int n;

    void buildSegmentTree(int ind, int left, int right, vector<int> & nums) {
        if(left == right)   {
            segTree[ind] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildSegmentTree(2 * ind + 1, left, mid, nums);
        buildSegmentTree(2 * ind + 2, mid + 1, right, nums);

        segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
    }

    void updateSegTree(int index, int val, int i, int l, int r) {
        if(l == r) {
            segTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if(index <= mid) {
            updateSegTree(index, val, 2 * i + 1, l , mid);
        } else {
            updateSegTree(index, val, 2 * i + 2, mid + 1 , r);
        }
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    int sumRangeQery(int start, int end, int ind, int left, int right) {
        if(left > end || right < start)   return 0;
        if(left >= start && right <= end)   return segTree[ind];

        int mid = left + (right - left) / 2;
        return sumRangeQery(start , end, 2 * ind + 1, left, mid) + sumRangeQery(start, end, 2 * ind + 2, mid + 1, right);
    }

    NumArray(vector<int>& nums) {
        n   = nums.size();
        segTree.resize(4 * n);

        buildSegmentTree(0, 0 , n - 1, nums);
    }
    
    void update(int index, int val) {
        updateSegTree(index, val, 0 , 0 , n - 1);
    }
    
    int sumRange(int left, int right) {
        return sumRangeQery(left, right, 0, 0, n - 1);
    }
};
