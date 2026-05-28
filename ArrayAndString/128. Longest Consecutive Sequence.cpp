class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = 0;
        unordered_set<int> st(nums.begin(), nums.end());



        for (auto& num : st) {
            
            if (!st.count(num - 1)) {
                int curr = num;
                int cnt = 1;

                while (st.count(curr + 1)) {
                    // do not erase i, not needed only skiping is enough
                    ++curr;
                    ++cnt;
                }
                len = max(cnt, len); 
            }



        }

        return len;
    }
};
