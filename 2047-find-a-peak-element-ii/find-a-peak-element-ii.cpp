class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                int left = (j > 0) ? mat[i][j-1] : -1;
                int up = (i > 0) ? mat[i-1][j] : -1;
                int right = (j < m-1) ? mat[i][j+1] : -1;
                int down = (i < n-1) ? mat[i+1][j] : -1;

                if(mat[i][j] > left  &&
                   mat[i][j] > up    && 
                   mat[i][j] > right &&
                   mat[i][j] > down) {
                    return {i,j};
                }
            }
        }
        return {};
    }
};