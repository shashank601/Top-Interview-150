class Solution {
public:
    vector<vector<int>> dp;
    int g(vector<vector<int>>& triangle, int c, int r) {
        int ht = triangle.size();
        int wt = triangle.back().size();
        if (c >= wt || r >= ht) {
            return 0;
        }

        if (dp[r][c] != INT_MIN) return dp[r][c];
        int curr = min(
            g(triangle, c, r + 1),
            g(triangle, c + 1, r + 1)
        ) + triangle[r][c];

        return dp[r][c] = curr;


    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.assign(200, vector<int>(200, INT_MIN));
        return g(triangle, 0, 0);
    }
};


=============

follow up:
