class Solution {
public:
    vector<long long> segTree;
    int n;

    void updateSegTree(int index, int i, int l, int r) {
        if(l == r) {
            segTree[i] = 1;
            return;
        }

        int mid = l + (r - l) / 2;
        if(index <= mid) {
            updateSegTree(index, 2 * i + 1, l , mid);
        } else {
            updateSegTree(index, 2 * i + 2, mid + 1 , r);
        }
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    long long sumRangeQery(int start, int end, int ind, int left, int right) {
        if(left > end || right < start)   return 0;
        if(left >= start && right <= end)   return segTree[ind];

        int mid = left + (right - left) / 2;
        return sumRangeQery(start , end, 2 * ind + 1, left, mid)
                            + 
                sumRangeQery(start, end, 2 * ind + 2, mid + 1, right);
    }


    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        segTree.resize(4 * n);
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[nums2[i]] = i;
        }

        long long ans = 0;
        updateSegTree(mp[nums1[0]], 0, 0, n - 1);

        for(int i = 1; i < n; i++) {
            int index = mp[nums1[i]];
            long long leftCommonCount = sumRangeQery(0, index, 0 , 0, n - 1);
            long long leftNotCommonCount = i - leftCommonCount;
            long long rightSideElement = (n - 1) - index;
            long long rightCommonCount = rightSideElement - leftNotCommonCount;

            ans += leftCommonCount * rightCommonCount;

            updateSegTree(index, 0, 0, n - 1);
        }
        return ans;
    }
};