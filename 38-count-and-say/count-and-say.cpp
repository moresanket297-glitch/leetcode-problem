class Solution {
public:
    string countAndSay(int n) {

        string ans = "1";

        for(int k = 1; k < n; k++) {

            string next = "";

            for(int i = 0; i < ans.size(); ) {

                int count = 0;
                char digit = ans[i];

                // Count consecutive same digits
                while(i < ans.size() && ans[i] == digit) {
                    count++;
                    i++;
                }

                // Add count + digit
                next += to_string(count);
                next += digit;
            }

            ans = next;
        }

        return ans;
    }
};