class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string p = strs[0];
        int n = strs.size();

        for (int i = 1; i < n; ++i) {
            string temp = "";

            int j = 0;
            int k = 0;

            int n1 = p.length();
            int n2 = strs[i].length();

            while (j < n1 && k < n2 && p[j] == strs[i][k]) {
                temp.push_back(p[j]);
                ++j;
                ++k;
            }

            p = temp;

            if (p.empty()) return "";

        }

        return p;
    }
};
