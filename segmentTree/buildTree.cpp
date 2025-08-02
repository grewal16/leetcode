class Solution {
    public: 

        void buildSegmentTree(int ind, int left, int right, vector<int>& segmentTree, int arr[]) {
            if(left == right) {
                segmentTree[ind] = left;
                return;
            }
            int mid = left + (right - left) / 2;
            buildSegmentTree(2 * ind + 1, left, mid, segmentTree, arr);
            buildSegmentTree(2 * ind + 2, mid + 1, right, segmentTree, arr);

            segmentTree[ind] = segmentTree[2 * ind + 1] + segmentTree[2 * ind + 2];
        }

        

        vector<int> segTree(int n, int arr[]) {
            vector<int> segmentTree(4*n);
            
            buildSegmentTree(0, 0, n-1, segmentTree, arr);
            
            return segmentTree;
        }
};