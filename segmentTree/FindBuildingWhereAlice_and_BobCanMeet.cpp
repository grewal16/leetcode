//Approach (Using Segment Tree Range Maximum Query + Binary Search)
//T.C : O(n + q*(logn)^2)
//S.C : O(n)


class Solution {
public:
    vector<int> segTree;
    int n;

    void buildTree(int i, int l, int r, vector<int>& arr) {
        if(l == r)  {
            segTree[i] = l;
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(2 * i + 1, l , mid, arr);
        buildTree(2 * i + 2, mid + 1, r, arr);

        segTree[i] = (arr[segTree[2 * i + 1]] >= arr[segTree[2 * i + 2]]) ? segTree[2 * i + 1] : segTree[2 * i + 2];
    }

    int RMIQ(int start, int end, int i, int  l , int r, vector<int> & arr) {
        if( l > end || r < start)   return -1;
        if( l >= start && r <= end )    return segTree[i];

        int mid = l + (r - l) / 2;

        int left = RMIQ(start, end,2 * i + 1, l, mid, arr);
        int right = RMIQ(start, end , 2 * i + 2, mid + 1, r, arr);

        if(left == -1)  return right;
        if(right == -1) return left;

        return arr[left] >= arr[right] ? left : right;
    }

    int querySum(vector<int>& heights, int n, int a, int b) {
        return RMIQ(a, b, 0, 0, n - 1, heights);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        n = heights.size();
        segTree.resize(4 * n);
        buildTree(0, 0, n - 1, heights);

        vector<int> result;

        for(auto i : queries) {
            int alice = min(i[0], i[1]);
            int bob = max(i[0], i[1]);

            if(alice == bob || heights[bob] > heights[alice]){
                result.push_back(bob);
                continue;
            }

            int left = bob + 1;
            int right = n - 1;
            int ans = INT_MAX;
            while( left <= right ){
                int mid = left + (right - left )/ 2;
                int index = querySum(heights, n, left, mid);

                if(heights[index] > max(heights[alice] , heights[bob])) {
                    right = mid - 1;
                    ans = index;
                } else {
                    left = mid + 1;
                }
            }
            if(ans == INT_MAX) 
                result.push_back(-1);
            else
                result.push_back(ans);
        }
        return result;
    }
};