class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int ans = 0;
        

        for (int r = m - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                if (matrix[r][c] == '1') {
                    // int b = r + 1 < m ? matrix[r + 1][c] : 0;
                    // int d = r + 1 < m && c + 1 < n ? matrix[r + 1][c + 1] : 0;

                    int b = r + 1 < m ?  dp[r + 1][c] : 0;
                    int right = c + 1 < n ? dp[r][c + 1] : 0;
                    int d = (c + 1 < n && r + 1 < m) ? dp[r + 1][c + 1] : 0;

                    dp[r][c] = min({b, right, d}) + 1;
                    ans = max(dp[r][c], ans);
                }
            }
        }   
        return ans * ans;
    
    }
};


==========

returned len; instead of area

assumed input is int

tried modifying char array for dp thinking its int matrix 

used wrong sentinel INT_MAX instead of zero for boundary condition

init last row seprately even though it had same logic as main loop

used r insetad of right  (vairable overshadowing)
