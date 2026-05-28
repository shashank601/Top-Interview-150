class Solution {
public:
    int dp[300];
    bool g(string& s, int idx, unordered_set<string>& st) {
        if (idx == s.length()) {
            return true;
        }
        if (dp[idx] != -1) return dp[idx];
        for (int i = idx; i < s.length(); i++) {
           
            if (st.count(s.substr(idx, i - idx + 1)) && g(s, i + 1, st)) {
                return true;
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        memset(dp, -1, sizeof(dp));
        for (auto& word : wordDict) {
            st.insert(word);
        }
        return g(s, 0, st);


    }
};


=========

add max len pruning


more better is to learn tri + dp  ( 0 ms )
