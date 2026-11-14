class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minS = INT_MAX;

        for(int i = 0; i < n; i++) {
            int curr = 0;
            for(int j = i; j < n; ++j) {
                curr += nums[j];
                int len = j - i + 1;

                if(len > r) {
                    break;
                }

                if(len >= l && curr > 0) {
                    minS = min(minS, curr);
                }
            }
        }
        return (minS == INT_MAX) ? -1 : minS;
    }
};