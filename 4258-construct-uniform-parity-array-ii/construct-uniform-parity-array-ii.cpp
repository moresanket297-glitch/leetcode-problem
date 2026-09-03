class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        int odd = INT_MAX;
        int even = INT_MAX;

        for(int x : nums1) {

            if(x % 2 == 0) {
                even = min(even, x);
            }
            else {
                odd = min(odd, x);
            }
        }
        if(odd == INT_MAX) {
            return true;
        }

        if(even != INT_MAX && odd < even) {
            return true;
        }
        
        if(even == INT_MAX) {
            return true;
        }
        return false;
    }
};