class Solution {
public:
    bool isPossible(vector<vector<int>>& tasks, int mid) {
        for(int i = 0; i < tasks.size(); i++) {
            if(mid >= tasks[i][1]) {
                mid -= tasks[i][0];
            }
            else {
                return false;
            }
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int st = 1;
        int end = 1000000;
        int ans = end;

        auto lambda = [](auto &task1, auto &task2) {
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];

            return diff1 > diff2;
        };

        sort(tasks.begin(), tasks.end(), lambda);

        while(st <= end) {

            int mid = st + (end - st) / 2;

            if(isPossible(tasks, mid)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }
        return ans;
    }
};