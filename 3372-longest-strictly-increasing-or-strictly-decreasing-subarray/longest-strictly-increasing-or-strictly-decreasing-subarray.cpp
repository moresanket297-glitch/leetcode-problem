class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int count = 1;
        int ans = 1;
        int de = 1;

        int i = 1;

        while(i < n) {

            if(nums[i] > nums[i - 1]) {
                count++;
                de = 1;
            }
            else if(nums[i] < nums[i - 1]) {
                de++;
                count = 1;
            }
            else {
                count = 1;
                de = 1;
            }

            ans = max(ans, max(count, de));

            i++;
        }
        return ans;
    }
};