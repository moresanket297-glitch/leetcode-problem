class Solution {
public:
    int maxDepth(string s) {

        int count = 0;
        int depth = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                depth++;
                count = max(count, depth);
            }
            if(s[i] == ')') {
                depth--;
            }
        }
        return count;
    }
};