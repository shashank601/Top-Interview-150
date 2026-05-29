class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = 0;
        int n = s.length();

        reverse(s.begin(), s.end());

        

        while (i < n) {
            string temp = "";

            while (i < n && s[i] == ' ') {
                i++;
            }

            while (i < n && s[i] != ' ') {
                temp.push_back(s[i]);
                i++;
            }

            if (!temp.empty()) {
                reverse(temp.begin(), temp.end());
                for (auto& ch : temp) {
                    ans.push_back(ch);
                }
            }


            while (i < n && s[i] == ' ') {
                i++;
            }

            if (i < n) {
                ans.push_back(' ');
            }

        }

        return ans;
    }
};
