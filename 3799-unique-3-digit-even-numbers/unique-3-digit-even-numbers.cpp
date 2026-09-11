class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> st;

        // Count frequency of each digit
        vector<int> freq(10, 0);

        for (int d : digits) {
            freq[d]++;
        }

        // Try every 3-digit number
        for (int num = 100; num <= 998; num++) {

            // Number must be even
            if (num % 2 != 0)
                continue;

            int a = num / 100;          // hundreds digit
            int b = (num / 10) % 10;    // tens digit
            int c = num % 10;           // units digit

            // Temporarily use digits
            freq[a]--;
            freq[b]--;
            freq[c]--;

            // If all digits are available
            if (freq[a] >= 0 && freq[b] >= 0 && freq[c] >= 0) {
                st.insert(num);
            }

            // Restore frequencies
            freq[a]++;
            freq[b]++;
            freq[c]++;
        }

        return st.size();
    }
};