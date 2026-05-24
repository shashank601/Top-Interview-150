class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;

        int ans = 0;

        int i = 0;
        for (int j = 0; j < s.length(); j++) {
            while (st.count(s[j])) {
                st.erase(s[i++]);
            }
            st.insert(s[j]);
            ans = max(j - i + 1, ans);
        }    

        return ans;
    }
};


======
gpt:
instead of using a set
directly track last index and jump st directly to it
