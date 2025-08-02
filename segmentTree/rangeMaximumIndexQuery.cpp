class Solution{
    private:
        vector<int> segTree;
        int n;
    public:
        void buildSegmentTree(int i , int l , int r, int arr[]) {
            if(l == r) {
                segTree[i] = l;
                return;
            }
            int mid = l + (r - l) / 2;
            buildSegmentTree(2 * i + 1, l , mid, arr);
            buildSegmentTree(2 * i + 2, mid + 1, r, arr);

            segTree[ind] = (arr[segTree[2 * i + 1]] >= arr[segTree[2 * i + 2]]) ? segTree[2 * i + 1] : segTree[2 * i + 2];
        }

        int* constructST(vector<int>& arr, int n) {
            n = arr.size();
            segTree.resize(4 * n);
            buildSegmentTree(0, 0, n - 1, arr);

            return segTree;
        }

        int querySegmentTree(int start, int end, int i, int l , int r, vector<int>& nums) {
            if(l > end || r < start)    return -1;
            if(l >= start && r <= end)  return segTree[i];

            int mid = l + (r - l) / 2;
            int left = querySegmentTree(start, end, 2 * i + 1, l, mid, nums);
            int right = querySegmentTree(start, end, 2 * i + 2, mid + 1, r, nums);

            if(left == -1)  return right;
            if(right == -1) return left;

            return nums[left] >= nums[right] ? left: right;
        }

        int RMIQ(vector<int>& arr, int n, int a, int b) {
            return querySegmentTree(a, b, 0, 0, n - 1, arr);
        }
};