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

        int querySegmentTree(int start, int end, int ind, int left, int right, vector<int>& segmentTree) {
            if(left > end || right < start) return 0;
            if(left >= start && right <= end)   return segmentTree[ind];

            int mid = left + (right - left) / 2;

            return querySegmentTree(start, end, 2 * ind + 1, left, mid , segmentTree) + querySegmentTree(start , end, mid + 1, end, segmentTree);
        }

        vector<int> querySum(int n, int arr[], int q, int queries[]) {
            vector<int> segmentTree(4*n);
            
            buildSegmentTree(0, 0, n-1, segmentTree, arr);
            
            vector<int> result;
            for(int i = 0; i < 2*q; i+=2) {
                int start = queries[i]-1;   
                int end   = queries[i+1]-1;
                
                result.push_back(querySegmentTree(start, end, 0, 0, n-1, segmentTree));
            }
            
            return result;
            
        }
};